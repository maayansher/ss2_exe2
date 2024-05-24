// name: Maayan Sher
// id: 208731091
// Email: maayan1sher@gmail.com
#include "Graph.hpp"
#include <string>
#include <iostream>
#include <vector>

using namespace std;
namespace ariel
{
    // Load the graph
    void Graph::loadGraph(const std::vector<std::vector<int>> &graph)
    {

        // Check if  the matrix is square
        // if the matrix is square we throw error
        for (unsigned int i = 0; i < graph.size(); i++)
        {
            if (graph.size() != graph[i].size())
            {
                throw invalid_argument("Invalid graph: The graph is not a square matrix.");
            }

            if (graph[i][i] != 0)
            {
                throw invalid_argument("Invalid graph.");
            }
        }
        matrix = graph;
    }

    int Graph::getNumOfEdges() const
    {
        int count = 0;
        for (size_t i = 0; i < this->size(); i++)
        {
            for (size_t j = 0; j < this->size(); j++)
            {
                if (this->matrix[i][j] != 0)
                {
                    count++;
                }
            }
        }
        return count;
    }

    vector<vector<int>> Graph::getAdjecenyMatrix() const
    {
        return matrix;
    }

    // Return string of the graph
    string Graph::printGraph() const
    {
        int count_all_edge_connected = 0;

        for (const auto &edge : matrix)
        {
            for (int num : edge)
            {
                if (num != 0)
                {
                    count_all_edge_connected++;
                }
            }
        }

        string result = "Graph with " + std::to_string(matrix.size()) + " vertices and " + to_string(count_all_edge_connected) + " edges.";
        return result;
    }

    unsigned int Graph::size() const
    {
        return matrix.size();
    }

    const int Graph::getEdge(unsigned int x, unsigned int y) const
    {

        // Check if we present in the bounds of the matrix
        if (x >= matrix.size() || y >= matrix[0].size())
        {
            throw out_of_range("Index out of range in the matrix");
        }

        return matrix[x][y];
    }

    vector<unsigned int> Graph::getAllVertices(unsigned int vertex) const
    {

        vector<unsigned int> all_vertices;

        if (vertex >= matrix.size())
        {
            throw out_of_range("Index out of range in the matrix");
        }

        const vector<int> &count_all_edge_connected = matrix[vertex];
        for (unsigned int i = 0; i < count_all_edge_connected.size(); ++i)
        {
            if (count_all_edge_connected[i] != 0)
            {
                all_vertices.push_back(i); // it is a connected vertice to the vertex so add to the vector
            }
        }

        return all_vertices;
    }

    // Transpose the vertices of the graph
    void Graph::transpose()
    {
        for (size_t i = 0; i < matrix.size(); i++)
        {
            for (size_t j = i + 1; j < matrix.size(); j++)
            {

                // Swap elements at position (i, j) and (j, i)
                int temp = matrix[i][j];
                matrix[i][j] = matrix[j][i];
                matrix[j][i] = temp;
                matrix[i][j];
            }
        }
    }

    // Operators implementation
    std::ostream &operator<<(std::ostream &os, const Graph &g1)
    {
        size_t size = g1.size();
        for (size_t i = 0; i < size; i++)
        {
            os << "[";
            for (size_t j = 0; j < size; j++)
            {
                os << g1.getAdjecenyMatrix()[i][j];
                if (j != size - 1)
                {
                    os << ",";
                }
            }
            os << "]\n";
        }
        return os;
    }

    Graph &Graph::operator++()
    {
        for (size_t i = 0; i < this->size(); i++)
        {
            for (size_t j = 0; j < this->size(); j++)
            {
                if (this->matrix[i][j] != 0)
                {
                    this->matrix[i][j] += 1;
                }
            }
        }
        return *this;
    }

    Graph Graph::operator++(int)
    {
        Graph g(*this);
        ++*this;
        return g;
    }

    Graph &Graph::operator+=(const Graph &g1)
    {
        if (this->size() != g1.size())
        {
            throw runtime_error("The graphs have different sizes! cannot add them together");
        }
        size_t size = g1.size();
        for (size_t i = 0; i < size; i++)
        {
            for (size_t j = 0; j < size; j++)
            {
                this->matrix[i][j] += g1.getAdjecenyMatrix()[i][j];
            }
        }
        return *this;
    }

    Graph Graph::operator+(const Graph &g1)
    {
        if (this->size() != g1.size())
        {
            throw runtime_error("The graphs have different sizes! cannot add them together");
        }
        Graph g(*this);
        size_t size = g1.size();
        for (size_t i = 0; i < size; i++)
        {
            for (size_t j = 0; j < size; j++)
            {
                g.matrix[i][j] += g1.getAdjecenyMatrix()[i][j];
            }
        }
        return g;
    }
    Graph &Graph::operator+(const int num)
    {
        for (size_t i = 0; i < this->size(); i++)
        {
            for (size_t j = 0; j < this->size(); j++)
            {
                if (this->matrix[i][j] != 0)
                {
                    this->matrix[i][j] += num;
                }
            }
        }
        return *this;
    }

    Graph Graph::operator+()
    {
        return *this;
    }

    Graph Graph::operator-(const Graph &g1)
    {
        if (this->size() != g1.size())
        {
            throw runtime_error("The graphs have different sizes! cannot add them together");
        }
        Graph g(*this);
        size_t size = g1.size();
        for (size_t i = 0; i < size; i++)
        {
            for (size_t j = 0; j < size; j++)
            {
                g.matrix[i][j] -= g1.getAdjecenyMatrix()[i][j];
            }
        }
        return g;
    }

    Graph &Graph::operator-=(const Graph &g1)
    {
        if (this->size() != g1.size())
        {
            throw runtime_error("The graphs have different size! cannot subtract them together");
        }
        size_t size = g1.size();
        Graph result;
        for (size_t i = 0; i < size; i++)
        {
            for (size_t j = 0; j < size; j++)
            {
                this->matrix[i][j] -= g1.getAdjecenyMatrix()[i][j];
            }
        }
        return *this;
    }

    Graph &Graph::operator--()
    {
        for (size_t i = 0; i < this->size(); i++)
        {
            for (size_t j = 0; j < this->size(); j++)
            {
                if (this->matrix[i][j] != 0)
                {
                    this->matrix[i][j] -= 1;
                }
            }
        }
        return *this;
    }

    Graph Graph::operator--(int)
    {
        Graph g(*this);
        --*this;
        return g;
    }

    Graph Graph::operator-()
    {
        return *this *= -1;
    }

    Graph &Graph::operator-(const int num)
    {
        for (size_t i = 0; i < this->size(); i++)
        {
            for (size_t j = 0; j < this->size(); j++)
            {
                if (this->matrix[i][j] != 0)
                {
                    this->matrix[i][j] -= num;
                }
            }
        }
        return *this;
    }

    Graph &Graph::operator*=(int num)
    {
        size_t size = this->size();
        for (size_t i = 0; i < size; i++)
        {
            for (size_t j = 0; j < size; j++)
            {
                if (this->matrix[i][j] != 0)
                {
                    this->matrix[i][j] *= num;
                }
            }
        }
        return *this;
    }

    Graph Graph::operator*(const Graph &g1)
    {
        if (this->size() != g1.size())
        {
            throw invalid_argument("The number of columns in the first matrix must be equal to the number of rows in the second matrix.");
        }
        vector<vector<int>> g(g1.size(), vector<int>(g1.size(), 0));
        size_t size = g1.size();

        for (size_t i = 0; i < size; i++)
        {
            for (size_t j = 0; j < size; j++)
            {
                for (size_t k = 0; k < size; k++)
                {
                    g[i][j] += this->getAdjecenyMatrix()[i][k] * g1.getAdjecenyMatrix()[k][j];
                }
            }
        }
        Graph g2;
        for (size_t i = 0; i < size; i++)
        {
            g[i][i] = 0; // initial the diagonal to zero since no edge from vertex to himself
        }

        g2.loadGraph(g);
        return g2;
    }

    Graph &Graph::operator/=(int num)
    {
        if (num == 0)
        {
            throw runtime_error("Cannot divide by zero!");
        }
        size_t size = this->size();
        for (size_t i = 0; i < size; i++)
        {
            for (size_t j = 0; j < size; j++)
            {
                if (this->matrix[i][j] != 0)
                {
                    this->matrix[i][j] /= num;
                }
            }
        }
        return *this;
    }

    bool Graph::operator==(const Graph &g1) const
    {
        size_t size = this->size();
        if (this->size() != g1.size())
        {
            return false;
        }
        if (this->getAdjecenyMatrix() != g1.getAdjecenyMatrix())
        {
            return false;
        }
        return true;
    }

    bool Graph::operator!=(const Graph &g1) const
    {
        if (*this == g1)
        {
            return false;
        }
        return true;
    }

    bool Graph::operator>(const Graph &g1) const
    {
        bool flag1 = true;
        if (*this == g1) // if they are the same graph *this cannot be bigger then g1
        {
            return false;
        }

        if (g1.size() == this->size())
        {
            flag1 = false;
        }
        if (g1.size() < this->size())
        {

            // Iterate over possible starting points where the g1 matrix can fit this.matrix

            for (size_t i = 0; i <= this->size() - g1.size(); i++)
            {
                for (size_t j = 0; j <= this->size() - g1.size(); j++)
                {
                    bool flag2 = true;
                    for (size_t k = 0; k < g1.size() && flag2; k++)
                    {
                        for (size_t l = 0; l < g1.size() && flag2; l++)
                        {
                            flag2 = this->matrix[i + k][j + l] == g1.matrix[k][l];
                        }
                    }
                    if (flag2)
                    {
                        return true;
                    }
                }
            }
        }
        /**
         * If the code reached here, it means this.matrix isnt containing g1.matrix
         * which means we need to check who contain more edges
         */
        if (this->getNumOfEdges() > g1.getNumOfEdges())
        {
            return true;
        }
        /**
         * If they have the same number of edges, check if this.matrix is bigger then g1,if so return true
         */
        if (this->getNumOfEdges() == g1.getNumOfEdges())
        {
            if (this->size() > g1.size())
            {
                return true;
            }
        }
        return flag1;
    }

    bool Graph::operator>=(const Graph &g1) const
    {
        return (*this == g1 || *this > g1);
    }

    bool Graph::operator<(const Graph &g1) const
    {
        return (g1 > *this);
    }

    bool Graph::operator<=(const Graph &g1) const
    {
        return (*this == g1 || *this < g1);
    }
}