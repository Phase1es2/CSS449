/*
 * @Author: your name
 * @Date: 2023-04-30 12:17:03
 * @LastEditTime: 2023-04-30 12:26:32
 * @LastEditors: momo.local
 * @Description: In User Settings Edit
 * @FilePath: /algorithm/prim.cpp
 */
#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <limits>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<pair<int, int>>> graph(n);
    for (int i = 0; i < m; i++) {
        char a, b;
        int c;
        cin >> a >> b >> c;

        int a_idx = a - 'A';
        int b_idx = b - 'A';
        graph[a_idx].push_back({b_idx, c});
        graph[b_idx].push_back({a_idx, c});
    }

    vector<bool> visited(n, false);
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
    pq.push({0, {0, -1}}); // start with node 0 (A), weight 0, parent -1

    int mst_weight = 0;
    vector<pair<int, int>> mst_edges;

    while (!pq.empty()) {
        int curr_weight = pq.top().first;
        int curr_node = pq.top().second.first;
        int parent_node = pq.top().second.second;
        pq.pop();

        if (visited[curr_node]) continue;
        visited[curr_node] = true;
        mst_weight += curr_weight;
        if (parent_node != -1) {
            mst_edges.push_back({parent_node, curr_node});
        }

        for (const auto& edge : graph[curr_node]) {
            if (!visited[edge.first]) {
                pq.push({edge.second, {edge.first, curr_node}});
            }
        }
    }

    cout << "Minimum spanning tree weight: " << mst_weight << endl;
    cout << "Edges in the minimum spanning tree: " << endl;
    for (const auto& edge : mst_edges) {
        cout << static_cast<char>(edge.first + 'A') << " " << static_cast<char>(edge.second + 'A') << endl;
    }
    return 0;
}
