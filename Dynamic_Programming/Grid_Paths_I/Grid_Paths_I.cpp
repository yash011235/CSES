/*
 * Problem Name: Grid_Paths_I
 * Language: C++
 * Category: Dynamic_Programming
 * Date: 2026-09-03
 */

#include<bits/stdc++.h>
using namespace std;
int n;
int ans = 0;
void solve(int i, int j, vector<vector<char>>&grid){
    if(i >= n || j >= n || grid[i][j] == '*'){
        return;
    }
    if(i == (n - 1) && j == (n - 1)){
        ans++;
    }
    solve(i + 1, j, grid);
    solve(i, j + 1, grid);
}
 
int main(){
    cin >> n;
    vector<vector<char>>grid(n, vector<char>(n));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> grid[i][j];
        }
    }
    solve(0, 0, grid);
    cout << ans << "\n";
}