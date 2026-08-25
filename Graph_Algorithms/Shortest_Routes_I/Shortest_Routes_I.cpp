/*
 * Problem Name: Shortest_Routes_I
 * Language: C++
 * Category: Graph_Algorithms
 * Date: 2026-08-25
 */

#include<bits/stdc++.h>
using namespace std;
int main(){
    long long n, m;
    cin >> n >> m;
    vector<vector<pair<long long, long long>>>adj(n);
    for(int i = 0; i < m; i++){
        int u, v, w;
        cin >> u >> v >> w;
        u--;
        v--;
        adj[u].push_back({v, w});
    }
    vector<long long>dist(n, LLONG_MAX);
    dist[0] = 0;
    priority_queue<pair<long long, long long>, vector<pair<long long, long long>>, greater<pair<long long, long long>>>pq;
    pq.push({0, 0});
    while(!pq.empty()){
        long long d = pq.top().first;
        long long node = pq.top().second;
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
    for(long long i = 0; i < n; i++){
        cout << dist[i] << " ";
    }
    cout << "\n";
}