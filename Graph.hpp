// name: Maayan Sher
// id: 208731091
// Email: maayan1sher@gmail.com
#ifndef GRAPH_HPP
#define GRAPH_HPP

#include <iostream>
#include <vector>
#include <string>

using namespace std;

namespace ariel
{
    class Graph
    {
        // representation of the graph by adjency matrix.
        vector<vector<int>> matrix;

    public:
        vector<vector<int>> getAdjecenyMatrix() const;
        /**
         * return the number of edges in the graph.
         */
        int getNumOfEdges() const;
        /**
         * loads a new graph from an adjacency matrix.
         */
        void loadGraph(const vector<vector<int>> &graph);

        /**
         * return a string  of the adjacency matrix.
         */
        string printGraph() const;

        /**
         * return the number of vertices in the graph.
         */
        unsigned int size() const;

        /**
         * return  the weight of the edge between two vertices.
         * If no edge  returns 0.
         */
        const int getEdge(unsigned int x, unsigned int y) const;

        /**
         * return all vertices that connected to specidific vertex
         */
        vector<unsigned int> getAllVertices(unsigned int vertex) const;

        /**
         * Transposes the graph by swapping the rows and columns of the adjacency matrix.
         */
        void transpose();

        /**
         * addition operators declartion
         */
        Graph &operator+=(const Graph &g1); // addition operator between two graphs(matrices)

        Graph &operator++(); // increment by one the exisiting edges of a matrix's graph(++G)

        Graph operator++(int); // increment by one the exisiting edges of matrix's graph(G++)

        Graph operator+(const Graph &g1); // addition operator between two graphs(matrices)

        Graph &operator+(const int num); // add integer to exisiting edges in a matrix's graph

        Graph operator+(); // unary plus to the matrix's graph

        /**
         * subtract operators declartion
         */

        Graph &operator-=(const Graph &g1); // subtract operator between two graphs(matrices)

        Graph &operator--(); // decreasing by one the exisiting edges of a matrix's graph(--G)

        Graph operator--(int); // decreasing by one the exisiting edges of a matrix's graph(G--)

        Graph operator-(const Graph &g1); // subtract operator between two graphs(matrices)

        Graph &operator-(const int num); // subtract integer from exisiting edges in a matrix's graph

        Graph operator-(); // unary minus to the matrix's graph

        /**
         * multiply/divide operators declartion
         */

        Graph &operator*=(int num); // multiply the matrix's graph by scalar

        Graph operator*(const Graph &g1); // multiply operator between two graphs(matrices)

        Graph &operator/=(int num); // divide the matrix's graph by scalar

        /**
         * Equal,bigger and smaller then operators declartion
         */
        bool operator==(const Graph &g1) const; // return 1 if the graphs are equal, else return 0

        bool operator!=(const Graph &g1) const; // return 1 if the graphs are not equal, else return 0

        bool operator>(const Graph &g1) const; // return 1 if first matrix is bigger then the second matrix(explained in the README)

        bool operator>=(const Graph &g1) const; // return 1 if first matrix is bigger then or equal to the second matrix(explained in the README)

        bool operator<(const Graph &g1) const; // return 1 if first matrix is smaller then the second matrix(explained in the README)

        bool operator<=(const Graph &g1) const; // return 1 if first matrix is smaller then or equal to the second matrix(explained in the README)

        friend ostream &operator<<(ostream &os, const Graph &g1); // print each row of the matrix's graph
    };
}

#endif