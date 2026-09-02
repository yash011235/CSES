/*
 * Problem Name: Removing_Digits
 * Language: C++
 * Category: Dynamic_Programming
 * Date: 2026-09-02
 */

#include<bits/stdc++.h>
using namespace std;
vector<int>dp;
int solve(int n){
    if(n == 0){
        return 0;
    }
    if(n >= 1 && n <= 9){
        return 1;
    }
    if(n < 0){
        return INT_MAX;
    }
    if(dp[n] != -1){
        return dp[n];
    }
    int ans = INT_MAX;
    string temp = to_string(n);
    for(char c : temp){
        if(c != '0'){
        int temp = 1 + solve(n - (c - '0'));
        ans = min(ans, temp);
     }
    }
    return dp[n] = ans;
}
 
 
 
int main(){
    int n;
    cin >> n;
    dp.assign(n + 1, -1);
    int ans = solve(n);
    cout << ans << "\n";
}