/*
 * Problem Name: Shortest_Routes_I
 * Language: C++
 * Category: Graph_Algorithms
 * Date: 2026-08-25
 */

#include<bits/stdc++.h>
using namespace std;
int main(){
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int, int>>>adj(n);
    for(int i = 0; i < m; i++){
        int u, v, w;
        cin >> u >> v >> w;
        u--;
        v--;
        adj[u].push_back({v, w});
    }
    vector<int>dist(n, INT_MAX);
    dist[0] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>pq;
    pq.push({0, 0});
    while(!pq.empty()){
        int d = pq.top().first;
        int node = pq.top().second;
        pq.pop();
        if(d > dist[node]){
            continue;
        }
        for(auto &[nei, w] : adj[node]){
            if(dist[nei] > dist[node] + w){
                dist[nei] = w + dist[node];
                pq.push({dist[nei], nei});
            }
        }
    }
    for(int i = 0; i < n; i++){
        cout << dist[i] << " ";
    }
    cout << "\n";
}