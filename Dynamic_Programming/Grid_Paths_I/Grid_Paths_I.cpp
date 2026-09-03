/*
 * Problem Name: Grid_Paths_I
 * Language: C++
 * Category: Dynamic_Programming
 * Date: 2026-09-03
 */

#include <bits/stdc++.h>
using namespace std;
 
int n;
vector<vector<long long>> dp;
const int MOD = 1e9 + 7;
long long solve(int i, int j, vector<vector<char>>& grid) {
    if(i >= n || j >= n || grid[i][j] == '*') {
        return 0;
    }
 
    if(i == n - 1 && j == n - 1) {
        return 1;
    }
 
    if(dp[i][j] != -1) {
        return dp[i][j];
    }
 
    long long down = solve(i + 1, j, grid) % MOD;
    long long right = solve(i, j + 1, grid) % MOD;
 
    return dp[i][j] = (down + right) % MOD;
}
 
int main() {
    cin >> n;
 
    vector<vector<char>> grid(n, vector<char>(n));
 
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }
 
    dp.assign(n, vector<long long>(n, -1));
 
    cout << (solve(0, 0, grid) % MOD) << "\n";
}