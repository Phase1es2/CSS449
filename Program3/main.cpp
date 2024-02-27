/*
 * @Author: Hao Yang
 * @Date: 2023-05-09 12:17:37
 * @LastEditTime: 2023-05-26 21:56:36
 * @LastEditors: momo.local
 * @Description: In User Settings Edit
 * @FilePath: /Program3/main.cpp
 */

// g++ -g -std=c++11 -Wall -Wextra -Wno-sign-compare *.cpp

// This program is implement the Ford-Fulkerson algorithm using the shortest
// augmenting paths methos for biapartite maching.
// The inputfile should be hardcoded to have the name "program3data.txt"
// The first line will hold the number of the nodes, which will be even.
// The next n/2 lines will be store the names of items to be matched in the
// "left" set. Then, n/2 further lines will store the names of item to be
// matching in the "right" set. Next, the number of edges will be stored and
// following that will be the edges(one per line) indexing the node using
// 1-based indexing.
// should be able to handle at least 100 Nodes. The code housld run in
// O(n^(5/2)) times.

#include "graph.h"
#include "nameList.h"

using namespace std;

int main() {
  Graph g;                         // Create an instance of Graph class
  g.readEdge("program3data.txt");  // Read edges from a text file and stroe them
                                   // in the Graph instacnce

  int total = g.dinic();  // Execute the Dinic's algorithm on the Graph instance
                          // and get the toatl flow.
  g.printMatch();  // Print the matched pair of names according to the result
                   // of the Dinic algorithm/
  printf("%d total matches\n", total);  // print the total number of matches.

  return 0;
}