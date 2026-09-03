/*
 * Problem Name: Coin_Combinations_I
 * Language: C++
 * Category: Dynamic_Programming
 * Date: 2026-09-03
 */

#include <bits/stdc++.h>
using namespace std;
 
int n;
long long x;
const int MOD = 1e9 + 7;
vector<long long>dp;
long long solve(vector<long long>&a, long long x){
    if(x == 0){
        return 1;
    }
    if(x < 0){
        return INT_MIN;
    }
    if(dp[x] != -1){
        return dp[x];
    }
    int ans = 0;
    for(int i = 0; i < n; i++){
        int temp = solve(a, x - a[i]);
        if(temp != INT_MIN){
            ans = (ans % MOD + temp % MOD) % MOD;
        }
    }
    return dp[x] = ans % MOD;
}
 
int main() {
    cin >> n >> x;
    dp.assign(x + 1, -1);
    vector<long long>a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    cout << solve(a, x) % MOD;
}