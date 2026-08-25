/*
 * Problem Name: Labyrinth
 * Language: C++
 * Category: Graph_Algorithms
 * Date: 2026-08-25
 */

#include<bits/stdc++.h>
using namespace std;
 
int main(){
    int n, m;
    cin >> n >> m;
    int sr = -1;
    int sc = -1;
    int dr = -1;
    int dc = -1;
    vector<vector<char>>grid(n, vector<char>(m));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            char x;
            cin >> x;
            if(x == 'A'){
                sr = i;
                sc = j;
            }
            if(x == 'B'){
                dr = i;
                dc = j;
            }
            grid[i][j] = x;
        }
    }
    vector<int>xr = {-1, 1, 0, 0};
    vector<int>xc = {0, 0, -1, 1};
    vector<char> moves = {'U', 'D', 'L', 'R'};
    queue<pair<int, int>>q;
    vector<vector<int>>dist(n, vector<int>(m, INT_MAX));
    vector<vector<char>>path(n, vector<char>(m));
    dist[sr][sc] = 0;
    q.push({sr, sc});
    while(!q.empty()){
        int r = q.front().first;
        int c = q.front().second;
        q.pop();
        for(int k = 0; k < 4; k++){
            int nr = r + xr[k];
            int nc = c + xc[k];
            if(nr >= 0 && nc >= 0 && nr < n && nc < m && grid[nr][nc] != '#' && dist[nr][nc] == INT_MAX){
                dist[nr][nc] = 1 + dist[r][c];
                q.push({nr, nc});
                path[nr][nc] = moves[k];
            }
        }
    }
    if(dist[dr][dc] == INT_MAX){
        cout << "NO\n";
        return 0;
    }
    cout << "YES\n";
    cout << dist[dr][dc] << "\n";
    string ans;
    int i = dr;
    int j = dc;
    while(grid[i][j] != 'A'){
        ans.push_back(path[i][j]);
        if(path[i][j] == 'U'){
            i++;
        }
        else if(path[i][j] == 'D'){
            i--;
        }
        else if(path[i][j] == 'L'){
            j++;
        }
        else{
            j--;
        }
    }
    reverse(ans.begin(), ans.end());
    for(char &x : ans){
        cout << x;
    }
    cout << "\n";
}