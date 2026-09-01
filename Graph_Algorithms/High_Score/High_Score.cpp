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
 
    for (int i = 0; i < m; i++) {
        int u, v;
        long long w;
 
        cin >> u >> v >> w;
 
        u--;
        v--;
 
        edges.push_back({u, v, w});
    }
 
    vector<long long> dist(n, LLONG_MIN);
    dist[0] = 0;
 
    for (int i = 0; i < m - 1; i++) {
        for (auto &e : edges) {
            if (dist[e.u] != LLONG_MIN &&
                dist[e.v] < dist[e.u] + e.w) {
 
                dist[e.v] = dist[e.u] + e.w;
            }
        }
    }
    long long x = dist[n - 1];
    for (auto &e : edges) {
        if (dist[e.u] != LLONG_MIN &&
            dist[e.v] < dist[e.u] + e.w) {
                dist[e.v] = dist[e.u] + e.w;
        }
    }
    if(dist[n - 1] > x){
        cout << -1 << "\n";
    }
    else{
        cout << dist[n - 1] << '\n';
    }
}