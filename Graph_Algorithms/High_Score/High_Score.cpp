/*
 * Problem Name: High_Score
 * Language: C++
 * Category: Graph_Algorithms
 * Date: 2026-09-01
 */

#include <bits/stdc++.h>
using namespace std;
 
struct Edge {
    int u, v;
    long long w;
};
 
int main() {
    int n, m;
    cin >> n >> m;
 
    vector<Edge> edges;
    vector<vector<int>> rev(n);
 
    for (int i = 0; i < m; i++) {
        int u, v;
        long long w;
 
        cin >> u >> v >> w;
 
        u--;
        v--;
 
        edges.push_back({u, v, w});
        rev[v].push_back(u);
    }
 
    // Find vertices from which n is reachable
    vector<bool> canReachN(n, false);
    queue<int> q;
 
    canReachN[n - 1] = true;
    q.push(n - 1);
 
    while (!q.empty()) {
        int u = q.front();
        q.pop();
 
        for (int v : rev[u]) {
            if (!canReachN[v]) {
                canReachN[v] = true;
                q.push(v);
            }
        }
    }
 
    // Bellman-Ford for maximum distance
    vector<long long> dist(n, LLONG_MIN);
    dist[0] = 0;
 
    for (int i = 0; i < n - 1; i++) {
        for (auto &e : edges) {
            if (dist[e.u] != LLONG_MIN &&
                dist[e.v] < dist[e.u] + e.w) {
 
                dist[e.v] = dist[e.u] + e.w;
            }
        }
    }
 
    // Check for a positive cycle affecting the answer
    for (auto &e : edges) {
        if (dist[e.u] != LLONG_MIN &&
            dist[e.v] < dist[e.u] + e.w &&
            canReachN[e.v]) {
 
            cout << -1 << '\n';
            return 0;
        }
    }
 
    cout << dist[n - 1] << '\n';
 
    return 0;
}