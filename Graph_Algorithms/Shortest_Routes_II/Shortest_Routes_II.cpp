/*
 * Problem Name: Shortest_Routes_II
 * Language: C++
 * Category: Graph_Algorithms
 * Date: 2026-08-25
 */

#include<bits/stdc++.h>
using namespace std;
 
int main(){
    long long n, m, q;
    cin >> n >> m >> q;
    vector<vector<long long>> dist(n, vector<long long>(n, LLONG_MAX));
    for(long long i = 0; i < m; i++){
        long long u, v, w;
        cin >> u >> v >> w;
        u--;
        v--;
        dist[u][v] = min(w, dist[u][v]);
        dist[v][u] = min(w, dist[v][u]);
    }
    for(long long i = 0; i < n; i++){
        dist[i][i] = 0;
    }
    for(long long k = 0; k < n; k++){
        for(long long i = 0; i < n; i++){
            for(long long j = 0; j < n; j++){
                if(dist[i][k] != LLONG_MAX && dist[k][j] != LLONG_MAX){
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
    }
    while(q--){
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        if(dist[a][b] == LLONG_MAX)
            cout << -1 << "\n";
        else
        cout << dist[a][b] << "\n";
    }
}