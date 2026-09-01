/*
 * Problem Name: Book_Shop
 * Language: C++
 * Category: Dynamic_Programming
 * Date: 2026-09-01
 */

#include<bits/stdc++.h>
using namespace std;
int n;
int x;
vector<vector<int>>dp;
int solve(vector<int>&pages, vector<int>&prices, int i, int amount){
    if(amount < 0 || i >= n){
        return 0;
    }
    if(dp[i][amount] != -1){
        return dp[i][amount];
    }
    int incl = 0;
    if(amount >= prices[i])
    incl = pages[i] + solve(pages, prices, i + 1, amount - prices[i]);
    int excl = 0 + solve(pages, prices, i + 1, amount);
    return dp[i][amount] = max(incl, excl);
}
 
int main(){
    cin >> n >> x;
    vector<int>prices(n);
    vector<int>pages(n);
    dp.assign(n, vector<int>(x + 1, -1));
    for(int i = 0; i < n; i++){
        cin >> prices[i];
    }
    for(int i = 0; i < n; i++){
        cin >> pages[i];
    }
    int ans = solve(pages, prices, 0, x);
    cout << ans << "\n";
}