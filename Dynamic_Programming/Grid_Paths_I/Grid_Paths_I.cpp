/*
 * Problem Name: Grid_Paths_I
 * Language: C++
 * Category: Dynamic_Programming
 * Date: 2026-09-03
 */

#include<bits/stdc++.h>
using namespace std;
int n;
vector<vector<int>>dp;
int solve(int i, int j, vector<vector<char>>&grid){
    if(i >= n || j >= n || grid[i][j] == '*'){
        return 0;
    }
    if(i == (n - 1) && j == (n - 1)){
        return 1;
    }
    if(dp[i][j] != -1){
        return dp[i][j];
    }
    return dp[i][j] = solve(i + 1, j, grid) + solve(i, j + 1, grid);
}
 
int main(){
    cin >> n;
    vector<vector<char>>grid(n, vector<char>(n));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> grid[i][j];
        }
    }
    dp.assign(n, vector<int>(n, -1));
    int ans = solve(0, 0, grid);
    cout << ans << "\n";
}