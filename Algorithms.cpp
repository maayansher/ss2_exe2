//name: Maayan Sher
//id: 208731091
//Email: maayan1sher@gmail.com

#include "Algorithms.hpp"
#include <vector>
#include <climits>
#include <queue> 


using namespace ariel;



bool Algorithms::isConnected(Graph& graph) {

    vector<bool> visited(graph.size(), false);
    DFS(graph, 0, visited);

    // check if all vertices was visited in the origin graph 
    for (bool vis : visited) {
        if (!vis){
            return false;// we find a vertex not visited so return false
        }
    }
    //transpose the graph and 
    // check if all vertices was visited in the transpose graph 
    graph.transpose();
    fill(visited.begin(), visited.end(), false); 
    DFS(graph, 0, visited);

    // Transpose to the origin grapb 
    graph.transpose();

    // check if all vertices was visited in the transpose  graph
    for (bool vis : visited) {
        if (!vis){
            return false; // find a vertex not visited so return false
        }
    }

    return true;
}


string Algorithms::shortestPath(const Graph& graph, const unsigned int s, const unsigned int end) {

    const unsigned int num_vertex = graph.size();

    if(s >= num_vertex || end >= num_vertex) {
        throw invalid_argument("Invalid values:The s vertex and the end vertex not in the range of the matrix .");
    }

    vector<int> distance(num_vertex, INT_MAX); 
    distance[s] = 0; 
    vector<int> pred(num_vertex, -1); 

    for (unsigned int i = 0; i < num_vertex; i++) {
        for (unsigned int j = 0; j < num_vertex; j++) {
            for (unsigned int k = 0; k < num_vertex; k++) {

                if(graph.getEdge(j,k) != 0) {

                   
                    if (distance[j] != INT_MAX && distance[j] + graph.getEdge(j,k) < distance[k]) {

    
                        distance[k] = distance[j] + graph.getEdge(j,k);

                       
                        pred[k] = static_cast<int>(j);
                    }
                }
            }
        }
    }


    // Checking if negative cycle in the path .if yes so no shortest path
    for (unsigned int j = 0; j < num_vertex; j++) {
        for (unsigned int k = 0; k < num_vertex; k++) {

            if(graph.getEdge(j,k) != 0) {

               
                if (distance[j] != INT_MAX && distance[j] + graph.getEdge(j,k) < distance[k]) {

                   
                    return "No shortest path because found negative cycle.";
                }
            }
        }
    }

    // check if we found result_biparite_path
    if (distance[static_cast<unsigned int>(end)] == INT_MAX) {
        return "-1";
    }

  
    string result_biparite_path = to_string(end);

    for (unsigned int n = end; n != s; n = static_cast<unsigned int>(pred[n])) {
        result_biparite_path.insert(0, "->");
        result_biparite_path.insert(0, to_string(pred[n]));
    }

    return result_biparite_path;
}


string Algorithms::isContainsCycle(const Graph& graph) {

    const unsigned int num_vertex = graph.size(); 
    vector<bool> visited(num_vertex, false);

    vector<unsigned int> pred(num_vertex, INT_MAX);

    string result_biparite_cycle = "";

    for (unsigned int i = 0; i < num_vertex; i++) {
        if (!visited[i]) {
            if (DFS_Cycle(i, INT_MAX, graph, visited, pred, result_biparite_cycle)) {

                unsigned int count = 0;
                for (const char ch : result_biparite_cycle) {
                    if (ch == '>') {
                        count++;
                    }
                }
                if (count>= 2) {
                    return result_biparite_cycle;
                }

                else {
                    result_biparite_cycle = "";
                    fill(visited.begin(), visited.end(), false);
                }
            }
        }
    }

    
    return "0";
}



string Algorithms::isBipartite(const Graph& graph) {

    const unsigned int num_vertex = graph.size(); 
    vector<int> vec_colors(num_vertex, -1);

    unordered_set<unsigned int> color1;
    unordered_set<unsigned int> color2;
    string result_biparite = ""; 


    for (unsigned int i = 0; i < num_vertex; i++) {
        if (vec_colors[i] == -1) {

            if (!BFS(graph, i, vec_colors, color1, color2)) {
                return "The graph is not bipartite"; 
            }
        }
    }

    result_biparite = "The graph is bipartite: color1={";
    string s1;

    // Go over the elements in the set
    for (const unsigned int elem : color1) {
        s1 = ", " + to_string(elem) + s1;
    }

    // Erase the first two characters
    if (!s1.empty()) {
        s1.erase(0, 2);
    }

    result_biparite.append(s1);
    result_biparite.append("}, color2={");
    string s2;

    // Go over the elements in the set
    for (const unsigned int elem : color2) {
        s2 = ", " + to_string(elem) + s2;
    }

    // Erase the first two characters
    if (!s2.empty()) {
        s2.erase(0, 2);
    }


    result_biparite.append(s2);
    result_biparite.append("}.");
    return result_biparite;
}


string Algorithms::negativeCycle(const Graph& graph) {

    const unsigned int num_vertex = graph.size(); 
    for(unsigned int i = 0; i < num_vertex; i++) {
        if(shortestPath(graph, i, i) == "No shortest path because found negative cycle.") {

            
            return "The graph contains negative cycle";
        }
    }

    
    return "The graph not contains negative cycle";
}


void Algorithms::DFS(const Graph& graph, unsigned int vis, vector<bool>& visited) {
    visited[vis] = true;

    vector<unsigned int> all_vertices=graph.getAllVertices(vis);
    for (unsigned int i : all_vertices) {

    
        if (!visited[i]) {

            DFS(graph, i, visited);
        }
    }
}


bool Algorithms::DFS_Cycle(const unsigned int node, unsigned int parentNode, const Graph& graph, vector<bool>& visited, vector<unsigned int>& parent, string& result_biparite_cycle) {

    visited[node] = true;
    parent[node] = parentNode; 

    vector<unsigned int> all_vertices=graph.getAllVertices(node);
    for (const unsigned int i :all_vertices) {

        if (!visited[i]) {
            if (DFS_Cycle(i, node, graph, visited, parent, result_biparite_cycle)) {
                return true; 
            }
        }

        else if (i != parentNode) {

            unsigned int n = node;
            result_biparite_cycle = "The cycle is: " + to_string(i); 
            
            while (n != INT_MAX && n != i) {
                result_biparite_cycle += "->" + std::to_string(n); 
                n = parent[n];
            }

            result_biparite_cycle += "->" + to_string(i); 

            return true;
        }
    }

    
    return false;
}

bool Algorithms::BFS(const Graph& graph, const unsigned int s, vector<int>& vec_colors, unordered_set<unsigned int>& color1, unordered_set<unsigned int>& color2) {

    queue<unsigned int> que;
    que.push(s); 

    bool set_1 = false;
    bool set_2 = false;
    vector<unsigned int> all_vertices=graph.getAllVertices(s);
    for(const unsigned int i : all_vertices) {
        if (vec_colors[i] == 1) {
            set_1 = true;
        }
        if (vec_colors[i] == 2) {
            set_2 = true;
        }
    }

    if (set_1 && set_2) {
        return false;
    }

    if(set_1) {
        vec_colors[static_cast<unsigned int>(s)] = 2;
        color2.insert(s);
    }

    else {
        vec_colors[s] = 1; 
        color1.insert(s);
    }


    while (!que.empty()) {

        unsigned int q_vertex = que.front();
        que.pop();

        
        for (const unsigned int j : graph.getAllVertices(q_vertex)) {

            if (vec_colors[j] == -1) {

                vec_colors[j] = 3 - vec_colors[q_vertex]; 
                if(vec_colors[j] == 1) {
                    color1.insert(j);
                }
                else {
                    color2.insert(j);
                }

                que.push(j);
            }

                
            else if (vec_colors[j] == vec_colors[q_vertex]) {
                return false; 
            }
        }
    }

    return true; 
}

