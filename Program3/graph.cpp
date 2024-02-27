/*
 * @Author: Hao Yang
 * @Date: 2023-05-09 11:25:01
 * @LastEditTime: 2023-05-26 21:48:29
 * @LastEditors: momo.local
 * @Description: In User Settings Edit
 * @FilePath: /Program3/graph.cpp
 */
#include "graph.h"

#include <fstream>
/**
 * @brief Constructor for Graph class. Initializes all arrays to their default
 * states.
 */
Graph::Graph() : idx(0) {
  memset(head, -1, sizeof head);
  memset(e, 0, sizeof e);
  memset(ne, 0, sizeof ne);
  memset(q, 0, sizeof q);
}
/**
 * @brief Function to add an edge to the graph.
 *
 * @param a The index of the first node.
 * @param b The index of the second node.
 * @param c TThe weight of the edge.
 */
void Graph::addEdge(int a, int b, int c) {
  // When we connect the edge, we connect one edge from 'a' to 'b' with weight
  // 'c', which means that 'b's capacity is 'c'. Then, we connect a reverse edge
  // from 'b' to 'a'.
  // Since there is no flow to the cancel out in the opposite direction yet, we
  // set f[idx] = 0 for the reverse edge.
  // Therefore, all edges from 'a' to 'b' will be even-numbered,
  // and all reverse edges from 'b' to 'a' will be odd-numbered.
  // To find the reverse edge from 'a' to 'b', we can use the index of 'a' to
  // 'b' XOR 1.
  e[idx] = b, f[idx] = c, ne[idx] = head[a], head[a] = idx++;
  e[idx] = a, f[idx] = 0, ne[idx] = head[b], head[b] = idx++;
  // h[] stores the head pointers for the adjacency list of each ndoe in the
  // graph. e[] represents the destination node of the i-th edge ne[] represents
  // the index of the nex edge in the adjacency list for the same source node.
  // f[] represents the capacity of the i-th node.
  // idx is used to keep track of current position in the edge list while adding
  // new edges.
}

/**
 * @brief Function to perform a Breadth-First Search (BFS) on the graph.

 * @return  A boolean value indicating whether the BFS was successful.
 */

bool Graph::bfs() {
  // hh and tt is using the array to simulate the queue.
  // hh is front of the queue.
  // tt is the tail of the queue.
  int hh = 0, tt = 0; 
  // reset the levle of the graph to -1 means that the node have not been
  // searched.
  memset(d, -1, sizeof d);
  // since none of the node has been searched, so we start from the source node
  // S.
  // Set the level(layer) for the soucre node to 0.
  // initialize the current arc to the first arc of the node S.
  q[0] = S, d[S] = 0, cur[S] = head[S];
  while (hh <= tt) {
    // Popo the front node from the queue.
    int t = q[hh++]; // same as auto t = q.front(), q.pop();
    // traverse all the neighboring nodes.
    for (int i = head[t]; ~i; i = ne[i]) {
      // record the current node.
      int ver = e[i];
      // if this node have not been visited, and it have cap greater than 0;
      if (d[ver] == -1 && f[i]) {
        // increase the level(layers) by 1 from the prvious level(layers)
        d[ver] = d[t] + 1;
        // Initialzie the current arc of the current node to its first arc.
        cur[ver] = head[ver];
        // if we reach to the sink the last point.
        // which means their is an arugmenting path fomr the source.
        if (ver == T) return true;
        // if we have not reached to the sink node yet, we add the node in the
        // to queue.
        q[++tt] = ver; //same as q.push(ver);
      }
    }
  }
  // If we have traversed all nodes and haven;t found a path to the sink, retru
  // fasle;
  return false;
}

/**
 * @brief Function to print the matching pairs in the graph.
 *
 */
void Graph::printMatch() {
  // Base on how we add the edge, we only need to check each edge from left to
  // right(forward edges);
  // If the flow is full, it represents a match.
  // traverse all the even idx, if the flow.
  // f[i] == 0 means that the flow is max.
  for (int i = 0; i < idx; i += 2)
    // if the flow on this edge have benn exhausted, and the node is points to
    // (e[i]) is a valid node. valid node is the node from 1 ~ n/2 connnect to
    // the node from n/2 + 1 ~ n; it means that this edge is part of the maximum
    // matching.
    if (e[i] > total / 2 && e[i] <= total && !f[i]) {
      // Find the mathcing pair.
      // e[i ^ 1] gives the node from which this edge originates (using the
      // property that reverse edges are stored in the next index)
      int left = e[i ^ 1], right = e[i];
      printf("%s / %s\n", list.getName(left).c_str(),
             list.getName(right).c_str());
      // printf("%s / %s\n", v[e[i ^ 1]].c_str(), v[e[i]].c_str());
    }
}

/**
 * @brief Function to find the maximum flow in the graph.
 *
 * @param u The start node.
 * @param limit The maximum flow limit.
 * @return      The maximum flow in the graph.
 */
int Graph::find(int u, int limit) {
  // If we reach the sink node, return the limit
  if (u == T) return limit;
  // flow is how much flow is moving forward from node u
  int flow = 0;
  // Start searching from the current unsaturated path
  for (int i = cur[u]; ~i && flow < limit; i = ne[i]) {
    // record the current arc
    //  we will only use the i=th edge when the arcs before i have been exhasted
    // update the current arc to i
    cur[u] = i;
    // record current node.
    int ver = e[i];
    // search according to the latered graph, so we need to ensuere that this
    // node is on teh next later of the prvious node
    if (d[ver] == d[u] + 1 && f[i]) {
      // starting from the current edge of u, how much flow can be allowed at
      // most The flow cannot exceed f[i] and cannot excedd limit -remaining
      // flow.
      int t = find(ver, std::min(f[i], limit - flow));
      // if there is no augmenting path, delete this node
      // by seting the number of layer to -1, this node will never be used
      if (!t) d[ver] = -1;

      // When building an edge, we create an edge from a to b and a reverse edge
      // from b to a. So if the edge from a to b is indexed as 0, then the
      // reverse edge from b to a is indexed as 1. These are paired together,
      // and the easiest way to find the reverse edge is to use the current
      // edge's index XOR 1. For example, 1 ^ 1 = 0, and 0 ^ 1 = 1. update the
      // current capacity - t update the capacity of the reverse arc + t update
      // flow += t;
      f[i] -= t, f[i ^ 1] += t, flow += t;
    }
  }
  return flow;
}

/**
 * @brief Function to find the maximum flow
 *
 * @return      TThe maximum flow in the graph.
 */
int Graph::dinic() {
  int r = 0, flow;
  // call bfs() function that help to build the level graph and reutrn that if
  // there is an augmenting path or not.
  while (bfs())
    while ((flow = find(S, INF)))
      r += flow;  // add all the augmenting path togather.
  return r;
}

/**
 * @brief Function to read the edges and name from a given file and add them to the
 * graph.
 *
 * @param fileName The name of the file to be read.
 */
void Graph::readEdge(const std::string& fileName) {
  // open the file
  int m;  // m is numer of node.
  std::ifstream file(fileName);
  if (!file) {
    std::cerr << "Unable to open the file" << fileName << std::endl;
    return;
  }
  // skip the first name part of the file
  file >> m;
  std::string name;
  for (int i = 0; i < m; i++) {
    file >> name;
    list.addToList(name); // add the name into the list; 
  }
  // use the n record the total number of the edge that added in the graph.
  // int n; // n = number of edge.
  file >> n;
  int a, b;
  // since the node is 1 based index, we could set the source as 0.
  S = 0;
  // set the sink to m + 1(node + 1);
  T = m + 1;
  total = m;  // total to record total node;
  // as the problem that first half of the node should be one the left, and
  // other half should be on the right.
  int half = m / 2;
  // connect one edge from source S with weight 1 to the each node on left.
  for (int i = 1; i <= half; i++) addEdge(S, i, 1);
  // connect one edge from each node on the right to sink T with weight 1.
  for (int i = half + 1; i <= m; i++) addEdge(i, T, 1);
  while (n--) {
    // read all the edge and added them to the graph.
    file >> a >> b;
    addEdge(a, b, 1);
  }
  file.close();
}