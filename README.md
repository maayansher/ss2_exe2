# ss2_exe2
## Descrtiption:
The following project implementing a functions overloading and mainly foucs on overloading basic operators such as addition, subtract, multiply and more.



## How to run the project
Use the provided `makefile` to build and run the project:
    
   - To build main:
        ```bash
        make all
        ```
  - To build tests:
      ```bash
      make test
      ```
  - To check for memory leaks using Valgrind:
      ```bash
      make valgrind
      ```

### Run the project
After compiling and building the wanted file:

- To run the demo
  ```bash
  ./demo
  ```
- To run the tests
  ```bash
  ./test
  ```

### Clean compiled files
To clean compiled files, run the command:
```bash
  make clean
  ```
## Explanation of the operators (on Graph.cpp\hpp):
On graph.hpp theres declaration for each operator i overloaded and on graph.cpp theres the implementation for each operator.

### Addition, incremention and Unary plus operators:
- `+=` : This operator is used to make addition between a graph to the current graph.
It take a graph as input and another graph to add to him, if they are not on the same size, an exception is thrown.  Example how to use: `g1+=g2`.

- `++` : This operator is used to increment a graph by one (only increment the existing edges on the graph).
Theres two usages of the ++ operator (++g and g++,prefix and postfix):
When we are using the g++ for example `cout<<g++` it will first print the current graph and then increment it by one.
When we are using the ++g for example `cout<<++g` it will print the current graph with incrementation by one.

- `+` : This operator is used for 3 purposes, first example:`g3 = g1 + g2` this will take the graphs g1 and g2, add the two graphs together and returns a new graph, in that example the new graph will be g3.(if they are not on the same size, an exception is thrown.)

second example is `g2 = g1 + 5` this will take the graph g1 and add an integer to each existing edge in the graph, in thie example it will add 5 to each edges and returns the new graph, in that example the new graph will be g2.

third example is `+g1` (Unary plus) this operator doesnt have any effect on the graph, return the graph itself.


### Subtract, decrement and Unary minus operators:

- `-=` : This operator is used to subtract a graph from the current graph.
It take a graph as input and another graph to subtract from him, if they are not on the same size, an exception is thrown.  Example how to use: `g1-=g2`.

- `--` : This operator is used to decrement a graph by one (only decrement the existing edges on the graph).
Theres two usages of the -- operator (--g and g--, prefix and postfix):
When we are using the g-- for example `cout<<g--` it will first print the current graph and then decrement it by one.
When we are using the --g for example `cout<<--g` it will print the current graph with incrementation by one.

- `-` : This operator is used for 3 purposes, first example:`g3 = g1 - g2` this will take the graphs g1 and g2, then subtract g2 from g1 and returns a new graph, in that example the new graph will be g3.(if they are not on the same size, an exception is thrown.)

second example is `g2 = g1 - 4` this will take the graph g1 and subtract an integer from each existing edge in the graph, in thie example it will subtract 4 from each edge and returns the new graph, in that example the new graph will be g2.

third example is `-g1` (Unary minus) this operator take the current graph(g1) and multiply each cell(that is not 0) by -1.

### Multiply and divide operators:

- `*=` : This operator is used to multiply the current graph by scalar (multiply each existing edge by the scalar). For example: `g4*=5` will multiply each edge in the graph by 5.

- `*` : This operator is used to multiply two graphs.
 as input,it takes the matrix of each graph and multiply the matrices then returns a new graph (after the multiplication it will change the diagonal to 0 since no edge can be from vertex to himself).
 if the graphs are not in the same size, an exception is thrown.
 For example: `g3 = g1 * g2` will multiply g1 matrix by g2 matrix and return it to g3.

- `/=` : This operator divides the existing edges of the graph by scalar.
If the scalar is 0, exception will be thrown.

### Print operator:

- `<<` : If this operator is used on a graph, it will print the graph's matrix row by row. This operator is overloading the print operator and prints us the adjacency matrix representing the graph.

### Equal, bigger, smaller then operators:

- `==` : This operator checks the adjacency matrix of two graphs and compare them, if they are the same matrix, return true, else return false.

- `!=` : This operator check the adjacency matrix of two graphs and compare them if they are not the same matrix, return true, else return false.

- `>` : This operator compare adjacency matrix of two graphs and checks if g1 is bigger then g2, for example: `g1 > g2`.
to determine if g1 is bigger then g2 we first checks if g1 contains but not equal to g2, if they are the same graph, return false.
After that we checks if they have the same number of vertices, if so, g1 cannot contain g2 because if g1 contains g2 it means its the same graph.
Now we check if g1 has more vertices then g2, if so, iterate over possible starting points where the g1 matrix can fit g2 matrix to see if g1 contains g2,if so return true else return false and check if g1 has more edges then g2,if so return true, else check if g1 has more vertices then g2, if so return true else return false.

- `>=` : This operator is combination of `>` and `==`, which means if we check `g1 >= g2`, we are gonna check if `g1 > g2` or `g1 == g2`.

- `<` : To implement this operator ive used the `>` operator but called the function with the paramters opposite place. for example: to check if `g1 < g2` ive called the function `>` with `g2 > g1`, which will give us the desire answer.

- `<=` : This operator is combination of `<` and `==`, which means if we check `g1 <= g2`, we are gonna check if `g1 < g2` or `g1 == g2`.
