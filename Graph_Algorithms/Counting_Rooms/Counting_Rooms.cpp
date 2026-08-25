/*
 * Problem Name: Counting_Rooms
 * Language: C++
 * Category: Graph_Algorithms
 * Date: 2026-08-25
 */

#include<bits/stdc++.h>
using namespace std;
 
vector<int>dr = {-1, 1, 0, 0};
vector<int>dc = {0, 0, -1, 1};
 
void bfs(int i, int j, vector<vector<char>>&grid, vector<vector<bool>>&visi, int n, int m){
    visi[i][j] = true;
    queue<pair<int, int>>q;
    q.push({i, j});
    while(!q.empty()){
        int r = q.front().first;
        int c = q.front().second;
        q.pop();
        for(int k = 0; k < 4; k++){
            int nr = r + dr[k];
            int nc = c + dc[k];
            if(nr >= 0 && nc >= 0 && nr < n && nc < m && !visi[nr][nc] && grid[nr][nc] == '.'){
                q.push({nr, nc});
                visi[nr][nc] = true;
            }
        }
    }
}
 
int main(){
    int n, m;
    cin >> n >> m;
    vector<vector<char>>grid(n, vector<char>(m));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> grid[i][j];
        }
    }
    int cnt = 0;
    vector<vector<bool>>visi(n, vector<bool>(m, false));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(!visi[i][j] && grid[i][j] == '.'){
                bfs(i, j, grid, visi, n, m);
                cnt++;
            }
        }
    }
    cout << cnt << "\n";
}