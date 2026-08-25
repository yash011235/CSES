/*
 * Problem Name: Building_Teams
 * Language: C++
 * Category: Graph_Algorithms
 * Date: 2026-08-25
 */

#include<bits/stdc++.h>
using namespace std;
 
bool dfs(vector<vector<int>>&adj, int i, vector<int>&visi, int c){
    visi[i] = c;
    for(int &nei : adj[i]){
        if(visi[nei] == 0){
            if(!dfs(adj, nei, visi, 3 - c)){
                return false;
            }
        }
        else if(visi[nei] == visi[i]){
            return false;
        }
    }
    return true;
}
 
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
    vector<int>visi(n, 0);
    for(int i = 0; i < n; i++){
        if(visi[i] == 0){
            if(!dfs(adj, i, visi, 1)){
                cout << "IMPOSSIBLE" << "\n";
                return 0;
            }
        }
    }
    for(int i = 0; i < n; i++){
        cout << visi[i] << " ";
    }
    cout << "\n";
}