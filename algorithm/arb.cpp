/*
 * @Author: your name
 * @Date: 2023-04-30 12:44:40
 * @LastEditTime: 2023-04-30 12:54:56
 * @LastEditors: momo.local
 * @Description: In User Settings Edit
 * @FilePath: /algorithm/arb.cpp
 */
#include <algorithm>
#include <iostream>
#include <limits>
#include <tuple>
#include <vector>

using namespace std;

int find(vector<int>& dsu, int x) {
  if (x != dsu[x]) {
    dsu[x] = find(dsu, dsu[x]);
  }
  return dsu[x];
}

bool unite(vector<int>& dsu, vector<int>& rank, int x, int y) {
  x = find(dsu, x);
  y = find(dsu, y);

  if (x == y) {
    return false;
  }
  if (rank[x] < rank[y]) {
    swap(x, y);
  }
  dsu[y] = x;
  if (rank[x] == rank[y]) {
    ++rank[x];
  }
  return true;
}

pair<int, vector<pair<int, int>>> chu_liu_edmonds(
    int n, int root, vector<tuple<int, int, int>>& edges) {
  vector<int> dsu(n), rank(n, 0), incoming(n, -1),
      cost(n, numeric_limits<int>::max());
  for (int i = 0; i < n; ++i) {
    dsu[i] = i;
  }

  for (const auto& [c, u, v] : edges) {
    if (v == root) continue;
    if (c < cost[v]) {
      cost[v] = c;
      incoming[v] = u;
    }
  }

  int mca_cost = 0;
  for (int i = 0; i < n; ++i) {
    if (i == root) continue;
    if (incoming[i] == -1)
      return {numeric_limits<int>::max(), {}};  // No solution
    mca_cost += cost[i];
  }

  vector<bool> cycle(n, false);
  for (int i = 0; i < n; ++i) {
    if (i == root) continue;
    int u = i;
    while (u != root && !cycle[u] && find(dsu, u) != find(dsu, root)) {
      cycle[u] = true;
      u = incoming[u];
    }
    if (u != root && !cycle[u]) {
      int v = incoming[u];
      while (v != u) {
        unite(dsu, rank, u, v);
        v = incoming[v];
      }
    }
  }

  if (find(dsu, 0) == find(dsu, n - 1)) {
    vector<pair<int, int>> mca_edges;
    for (int i = 1; i < n; ++i) {
      if (i != root) {
        mca_edges.emplace_back(incoming[i], i);
      }
    }
    return {mca_cost, mca_edges};
  }

  vector<tuple<int, int, int>> contracted_edges;
  for (const auto& [c, u, v] : edges) {
    if (find(dsu, u) != find(dsu, v)) {
      contracted_edges.emplace_back(c - cost[v], find(dsu, u), find(dsu, v));
    }
  }

  auto [contracted_cost, contracted_edges_list] =
      chu_liu_edmonds(n, root, contracted_edges);
  mca_cost += contracted_cost;
  vector<pair<int, int>> mca_edges;
  for (const auto& [u, v] : contracted_edges_list) {
    int u_repr = find(dsu, u);
    int v_repr = find(dsu, v);
    mca_edges.emplace_back(u_repr, v_repr);
    if (cycle[v_repr]) {
      int w = incoming[v_repr];
      while (w != u_repr) {
        mca_edges.emplace_back(w, v_repr);
        w = incoming[w];
      }
    }
  }
  return {mca_cost, mca_edges};
}

int main() {
  int n, m;
  cin >> n >> m;
  vector<tuple<int, int, int>> edges(m);
  for (int i = 0; i < m; ++i) {
    char a, b;
    int c;
    cin >> a >> b >> c;

    int a_idx = a - 'A';
    int b_idx = b - 'A';
    edges[i] = {c, a_idx, b_idx};
  }

  int root = 0;  // Assuming the root is node 0 (A)
  auto [mca_cost, mca_edges] = chu_liu_edmonds(n, root, edges);

  if (mca_cost == numeric_limits<int>::max()) {
    cout << "No minimum cost arborescence found" << endl;
  } else {
    cout << "Minimum cost arborescence: " << mca_cost << endl;
    cout << "Edges in the minimum cost arborescence: " << endl;
    for (const auto& [u, v] : mca_edges) {
      cout << static_cast<char>(u + 'A') << " " << static_cast<char>(v + 'A')
           << endl;
    }
  }

  return 0;
}