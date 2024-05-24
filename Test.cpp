// name: Maayan Sher
// id: 208731091
// Email: maayan1sher@gmail.com

#include "doctest.h"
#include "Algorithms.hpp"
#include "Graph.hpp"
#include <iostream>
#include <sstream>

using namespace std;

TEST_CASE("Operator<<")
{
    ariel::Graph g1;
    vector<vector<int>> graph1 = {
        {0, 1, 0, 0},
        {1, 0, 1, 0},
        {0, 1, 0, 1},
        {0, 0, 1, 0}};
    g1.loadGraph(graph1);

    stringstream output1;
    output1 << g1;
    string expectedOutput1 = "[0,1,0,0]\n[1,0,1,0]\n[0,1,0,1]\n[0,0,1,0]\n";
    CHECK(output1.str() == expectedOutput1);

    ariel::Graph g2;
    vector<vector<int>> graph2 = {
        {0, 4},
        {4, 0}};
    g2.loadGraph(graph2);

    stringstream output2;
    output2 << g2;
    string expectedOutput2 = "[0,4]\n[4,0]\n";
    CHECK(output2.str() == expectedOutput2);
}

TEST_CASE("Operator+=")
{
    vector<vector<int>> graph1 = {
        {0, 1, 1},
        {1, 0, 2},
        {1, 2, 0}};
    ariel::Graph g1;
    g1.loadGraph(graph1);

    vector<vector<int>> graph2 = {
        {0, 0, 1},
        {0, 0, 1},
        {1, 1, 0}};
    ariel::Graph g2;
    g2.loadGraph(graph2);

    vector<vector<int>> ans = {
        {0, 1, 2},
        {1, 0, 3},
        {2, 3, 0}};

    CHECK((g1 += g2).getAdjecenyMatrix() == ans);

    vector<vector<int>> graph3 = {
        {0, 1},
        {1, 0}};
    ariel::Graph g3;
    g3.loadGraph(graph3);

    CHECK_THROWS(g3 += g1); // different sizes of graphs cannot be added together
}

TEST_CASE("Operator++(++G)")
{
    vector<vector<int>> graph1 = {
        {0, 1, 4},
        {1, 0, 2},
        {4, 2, 0}};
    ariel::Graph g1;
    g1.loadGraph(graph1);

    vector<vector<int>> ans = {
        {0, 2, 5},
        {2, 0, 3},
        {5, 3, 0}};

    CHECK((++g1).getAdjecenyMatrix() == ans);
}

TEST_CASE("Operator++(G++)")
{
    vector<vector<int>> graph1 = {
        {0, 3},
        {3, 0}};
    ariel::Graph g1;
    g1.loadGraph(graph1);

    vector<vector<int>> ans = {
        {0, 4},
        {4, 0}};

    CHECK((g1++).getAdjecenyMatrix() == g1.getAdjecenyMatrix()); // prints the same matrix then adds one to all edges
    CHECK(g1.getAdjecenyMatrix() == ans);
}

// addition between two graphs and between graph and integer
TEST_CASE("Operator+")
{
    vector<vector<int>> graph1 = {
        {0, 3},
        {3, 0}};
    ariel::Graph g1;
    g1.loadGraph(graph1);

    vector<vector<int>> graph2 = {
        {0, 2},
        {2, 0}};
    ariel::Graph g2;
    g2.loadGraph(graph2);

    vector<vector<int>> ans1 = {
        {0, 5},
        {5, 0}};

    CHECK((g1 + g2).getAdjecenyMatrix() == ans1);

    ariel::Graph g3 = g1 + g2;
    g3 = g3 + 5;

    vector<vector<int>> ans2 = {
        {0, 10},
        {10, 0}};

    CHECK(g3.getAdjecenyMatrix() == ans2);
}

TEST_CASE("Operator+(unary)")
{
    vector<vector<int>> graph1 = {
        {0, 1, 2},
        {1, 0, 6},
        {2, 6, 0}};
    ariel::Graph g1;
    g1.loadGraph(graph1);

    CHECK((+g1).getAdjecenyMatrix() == g1.getAdjecenyMatrix());
}

TEST_CASE("Operator-=")
{
    vector<vector<int>> graph1 = {
        {0, 2, 0},
        {2, 0, 2},
        {0, 2, 0}};
    ariel::Graph g1;
    g1.loadGraph(graph1);

    vector<vector<int>> graph2 = {
        {0, 3, 0},
        {3, 0, 3},
        {0, 3, 0}};
    ariel::Graph g2;
    g2.loadGraph(graph2);

    vector<vector<int>> ans = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    CHECK((g2 -= g1).getAdjecenyMatrix() == ans);

    vector<vector<int>> graph3 = {
        {0, 1},
        {1, 0}};
    ariel::Graph g3;
    g3.loadGraph(graph3);

    CHECK_THROWS(g3 -= g1); // different sizes of graphs cannot be added together
}

TEST_CASE("Operator--(--G)")
{
    vector<vector<int>> graph1 = {
        {0, 3, 3},
        {3, 0, 2},
        {3, 2, 0}};
    ariel::Graph g1;
    g1.loadGraph(graph1);

    vector<vector<int>> ans = {
        {0, 2, 2},
        {2, 0, 1},
        {2, 1, 0}};

    CHECK((--g1).getAdjecenyMatrix() == ans);
}

TEST_CASE("Operator--(G--)")
{
    vector<vector<int>> graph1 = {
        {0, -3},
        {-3, 0}};
    ariel::Graph g1;
    g1.loadGraph(graph1);

    vector<vector<int>> ans = {
        {0, -4},
        {-4, 0}};

    CHECK((g1--).getAdjecenyMatrix() == g1.getAdjecenyMatrix()); // prints the same matrix then minus one to all edges
    CHECK(g1.getAdjecenyMatrix() == ans);
}

// subtract between two graphs and between graph and integer
TEST_CASE("Operator-")
{
    vector<vector<int>> graph1 = {
        {0, 1},
        {1, 0}};
    ariel::Graph g1;
    g1.loadGraph(graph1);

    vector<vector<int>> graph2 = {
        {0, 2},
        {2, 0}};
    ariel::Graph g2;
    g2.loadGraph(graph2);

    vector<vector<int>> ans1 = {
        {0, -1},
        {-1, 0}};

    CHECK((g1 - g2).getAdjecenyMatrix() == ans1);

    ariel::Graph g3 = g1 - g2;
    g3 = g3 - 5;

    vector<vector<int>> ans2 = {
        {0, -6},
        {-6, 0}};

    CHECK(g3.getAdjecenyMatrix() == ans2);
}

TEST_CASE("Operator-(unary)")
{
    vector<vector<int>> graph1 = {
        {0, 7, 1},
        {7, 0, 4},
        {1, 4, 0}};
    ariel::Graph g1;
    g1.loadGraph(graph1);

    vector<vector<int>> ans = {
        {0, -7, -1},
        {-7, 0, -4},
        {-1, -4, 0}};

    CHECK((-g1).getAdjecenyMatrix() == ans);
}

// multiply graph by scalar
TEST_CASE("Operator*")
{
    vector<vector<int>> graph1 = {
        {0, 5, 1},
        {5, 0, 3},
        {1, 3, 0}};
    ariel::Graph g1;
    g1.loadGraph(graph1);

    vector<vector<int>> ans1 = {
        {0, 10, 2},
        {10, 0, 6},
        {2, 6, 0}};

    CHECK((g1 *= 2).getAdjecenyMatrix() == ans1);

    vector<vector<int>> graph2 = {
        {0, 3},
        {3, 0}};
    ariel::Graph g2;
    g2.loadGraph(graph2);

    vector<vector<int>> ans2 = {
        {0, -9},
        {-9, 0}};

    CHECK((g2 *= -3).getAdjecenyMatrix() == ans2);
}

// multiply between two graphs
TEST_CASE("Operator*")
{
    vector<vector<int>> graph1 = {
        {0, 3, 5},
        {3, 0, 1},
        {5, 1, 0}};
    ariel::Graph g1;
    g1.loadGraph(graph1);

    vector<vector<int>> graph2 = {
        {0, 2, 0},
        {2, 0, 3},
        {0, 3, 0}};
    ariel::Graph g2;
    g2.loadGraph(graph2);

    vector<vector<int>> ans1 = {
        {0, 15, 9},
        {0, 0, 0},
        {2, 10, 0}};

    CHECK((g1 * g2).getAdjecenyMatrix() == ans1);

    vector<vector<int>> graph3 = {
        {0, 3},
        {3, 0}};
    ariel::Graph g3;
    g3.loadGraph(graph3);

    CHECK_THROWS(g3 * g1); // invalid multiplication,the graphs have different sizes
}

TEST_CASE("Operator/")
{
    vector<vector<int>> graph1 = {
        {0, 4, 0},
        {4, 0, 4},
        {0, 4, 0}};
    ariel::Graph g1;
    g1.loadGraph(graph1);

    vector<vector<int>> ans = {
        {0, -2, 0},
        {-2, 0, -2},
        {0, -2, 0}};

    CHECK((g1 /= -2).getAdjecenyMatrix() == ans);
}

TEST_CASE("Operators >,<,>=,<=,==,!=")
{
    vector<vector<int>> graph1 = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    ariel::Graph g1;
    g1.loadGraph(graph1);

    vector<vector<int>> graph2 = {
        {0, 1, 0},
        {1, 0, 1},
        {1, 1, 0}};
    ariel::Graph g2;
    g2.loadGraph(graph2);

    CHECK((g2 > g1) == true); // g2 contains g1
    CHECK((g2 < g1) == false);
    CHECK((g2 >= g1) == true);
    CHECK((g2 <= g1) == false);
    CHECK((g2 == g1) == false);
    CHECK((g2 != g1) == true);

    vector<vector<int>> graph3 = {
        {0, 3, 5},
        {3, 0, 1},
        {5, 1, 0}};
    ariel::Graph g3;
    g3.loadGraph(graph3);

    vector<vector<int>> graph4 = {
        {0, 2, 0},
        {2, 0, 3},
        {0, 3, 0}};
    ariel::Graph g4;
    g4.loadGraph(graph4);

    CHECK((g3 > g4) == true); // g3 doesnt contain g4, but g3 has more edges so g3 is bigger
    CHECK((g3 < g4) == false);
    CHECK((g3 >= g4) == true);
    CHECK((g3 <= g4) == false);
    CHECK((g3 == g4) == false);
    CHECK((g3 != g4) == true);

    vector<vector<int>> graph5 = {
        {0, 3, 4, 1},
        {3, 0, 2, 1},
        {4, 2, 0, 1},
        {1, 1, 1, 0}};
    ariel::Graph g5;
    g5.loadGraph(graph5);

    vector<vector<int>> graph6 = {
        {0, 3, 4, 1},
        {3, 0, 2, 1},
        {4, 2, 0, 1},
        {1, 1, 1, 0}};
    ariel::Graph g6;
    g6.loadGraph(graph6);

    CHECK((g5 > g6) == false); // g5 equals g6,so no one is bigger then the other
    CHECK((g5 < g6) == false);
    CHECK((g5 >= g6) == true);
    CHECK((g5 <= g6) == true);
    CHECK((g5 == g6) == true);
    CHECK((g5 != g6) == false);
}
