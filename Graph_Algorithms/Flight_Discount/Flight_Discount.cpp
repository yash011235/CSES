/*
 * Problem Name: Flight_Discount
 * Language: C++
 * Category: Graph_Algorithms
 * Date: 2026-09-01
 */

#include <bits/stdc++.h>
using namespace std;
 
using ll = long long;
 
struct Edge {
    int u, v;
    ll w;
};
 
vector<ll> dijkstra(int src, vector<vector<pair<int, ll>>>& adj) {
    int n = adj.size();
 
    vector<ll> dist(n, LLONG_MAX);
    priority_queue<
        pair<ll, int>,
        vector<pair<ll, int>>,
        greater<pair<ll, int>>
    > pq;
 
    dist[src] = 0;
    pq.push({0, src});
 
    while (!pq.empty()) {
        auto [d, node] = pq.top();
        pq.pop();
 
        if (d != dist[node])
            continue;
 
        for (auto [nei, w] : adj[node]) {
            if (dist[nei] > d + w) {
                dist[nei] = d + w;
                pq.push({dist[nei], nei});
            }
        }
    }
 
    return dist;
}
 
int main() {
    int n, m;
    cin >> n >> m;
 
    vector<vector<pair<int, ll>>> adj(n);
    vector<vector<pair<int, ll>>> rev(n);
    vector<Edge> edges;
 
    for (int i = 0; i < m; i++) {
        int u, v;
        ll w;
 
        cin >> u >> v >> w;
 
        u--;
        v--;
 
        adj[u].push_back({v, w});
        rev[v].push_back({u, w});
 
        edges.push_back({u, v, w});
    }
 
    vector<ll> dist1 = dijkstra(0, adj);
 
    vector<ll> distN = dijkstra(n - 1, rev);
 
    ll ans = LLONG_MAX;
 
    for (auto [u, v, w] : edges) {
        if (dist1[u] == LLONG_MAX || distN[v] == LLONG_MAX)
            continue;
 
        ll cost = dist1[u] + w / 2 + distN[v];
        ans = min(ans, cost);
    }
 
    cout << ans << '\n';
}