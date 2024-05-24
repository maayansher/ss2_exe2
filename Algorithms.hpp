//name: Maayan Sher
//id: 208731091
//Email: maayan1sher@gmail.com

#pragma once

#include "Graph.hpp"
#include <unordered_set> 

using namespace std;

namespace ariel {
    class Algorithms {
    public:
        /**
         * this function checks if the graph is strongly connected.
         * @param graph The graph 
         * @return True if the graph is strongly connected,other return false .
         */
        static bool isConnected(Graph& graph);

        /**
         * this function finds the shortest path between two vertices.to iplement this function we  using the Bellman-Ford algorithm from course algorithm.
         * @param graph The graph 
         * @param start The start vertex 
         * @param end The target vertex.
         * @return string that descript of the shortest path
         */
        static string shortestPath(const Graph& graph, unsigned int start, unsigned int end);



  /**
         * this function check if the graph is bipartite.
         * @param graph The graph 
         * @return a string that determine if the the graph is bipartite or no 
         */
        static string isBipartite(const Graph& graph);

        /**
         * this function check if the graph contains a negative cycle.
         * @param graph The graph 
         * @return a string that determine if the function find a negative cycle or no
         */
        static string negativeCycle(const Graph& graph);



        /**
         * this function check if the graph contains cycle.
         * @param graph The graph 
         * @return a string that determine if the function find a cycle or no
         */
        static string isContainsCycle(const Graph& graph);

      

    private:
    //the following functions are algorithms to help us implement the main functions in the project
        static bool BFS(const Graph& graph, unsigned int start, vector<int>& color, unordered_set<unsigned int>& A, unordered_set<unsigned int>& B);
        
        static void DFS(const Graph& graph, unsigned int v, vector<bool>& visited);

        static bool DFS_Cycle(unsigned int node, unsigned int parentNode, const Graph& graph, vector<bool>& visited, vector<unsigned int>& parent, string& cyclePath);
    };
}
