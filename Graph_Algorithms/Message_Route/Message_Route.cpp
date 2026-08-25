/*
 * Problem Name: Message_Route
 * Language: C++
 * Category: Graph_Algorithms
 * Date: 2026-08-25
 */

#include<bits/stdc++.h>
using namespace std;
 
int main(){
    int n, m;
    cin >> n >> m;
    vector<vector<int>>adj(n);
    for(int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int src = 0;
    int dst = n - 1;
    vector<int>dist(n, INT_MAX);
    dist[src] = 0;
    queue<int>q;
    q.push(src);
    vector<int>parent(n, -1);
    while(!q.empty()){
        int curr = q.front();
        q.pop();
        for(int &nei : adj[curr]){
            if(dist[nei] > 1 + dist[curr]){
                dist[nei] = 1 + dist[curr];
                q.push(nei);
                parent[nei] = curr;
            }
        }
    }
    if(dist[dst] == INT_MAX){
        cout << "IMPOSSIBLE" << "\n";
        return 0;
    }
    cout << dist[dst] + 1<< "\n";
    vector<int>path;
    int curr = n - 1;
    while(curr != -1){
        path.push_back(curr);
        curr = parent[curr];
    }
    reverse(path.begin(), path.end());
    for(int &p : path){
        cout << p + 1 << " ";
    }
    cout << "\n";
}