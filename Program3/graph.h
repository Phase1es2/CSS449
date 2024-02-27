/*
 * @Author: Hao Yang
 * @Date: 2023-05-09 11:25:06
 * @LastEditTime: 2023-05-26 21:45:33
 * @LastEditors: momo.local
 * @Description: In User Settings Edit
 * @FilePath: /Program3/graph.h
 */

// Graph class
// using the array to simulate adjacency graphs
// addEdge() The class allow to read the data from the inputfile
// dinic() return the maimum flow from the graph;
// PrintMatch() find the matching pair from the vector list
// bfs() helper fucntion that build the level graph and finding the augmenting
// path find() a helper function recusively fucnt ion maximum limit form source
// to u.
#ifndef GRAPH_H_
#define GRAPH_H_
#include <algorithm>
#include <cstring>
#include <iostream>
#include <string>

#include "nameList.h"

class Graph {
 public:
  // Constructor for Graph class.
  Graph();
  // Function to connect that edge from a to b witth weight c;
  void addEdge(int a, int b, int c);
  // Function to find the maximum flow in the graph.
  int dinic();
  // Fucntion that read the input from the input file.
  void readEdge(const std::string& fileName);
  // Fucntion to matching pairs in the graph base on the listed name.
  void printMatch();

 private:
  // The code should be able to handle at least 100 nodes plus an extra 10 in
  // case there is insufficient space.
  static const int N = 110;
  // M = edge. Each node on the left must connect to one edge to 's', so there
  // are 50 edges. Each node on the right must connect to one edge to 't', so
  // there are another 50 edges. Each node on the left might have one edge
  // connecting to each node on the right, resulting in 50 ^ 2 = 2500 edges. We
  // also need additional edges to connect backward, which gives us another
  // (2500 + 100) * 2 = 5200. An additional 10 is added in case there is not
  // enough space. Hence, the total will be 5210 edges.
  static const int M = 5210;
  static const int INF = 1e8;
  NameList list;  // create a NameList that called list to store the list of the
                  // input name;
  // using array to simulate adjacency graphs
  int head[N];  // stores the head pointers for the adjacency list of each ndoe
                // in the graph.
  int e[M];     // epresents the destination node of the i-th edge
  int ne[M];   // represents the index of the nex edge in the adjacency list for
               // the same source node.
  int f[M];    // f represents the capacity of the i-th node.
  int idx;     // idx is used to keep track of current position in the edge list
               // while adding new edges.
  int q[N];    // use the array tp simulate queue
  int d[N];    // d represent the level(layer) of the node.
  int cur[N];  // cur use the optimize the code.
  int n, S, T;  // n is the input value, S is the source, T is sink.
  int total;    // to record that how many edge have been added to the graph.
  // helper function that build the level graph and return if there is
  // augmenting path
  bool bfs();
  // dfs() helper fucntion help to find the maximum limit from source(S) to u.
  int find(int u, int limit);
};
#endif