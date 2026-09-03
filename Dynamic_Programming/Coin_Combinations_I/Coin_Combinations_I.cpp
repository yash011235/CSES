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
 
vector<long long> dp;
 
long long solve(vector<long long>& a, long long x) {
    if(x == 0) {
        return 1;
    }
 
    if(x < 0) {
        return 0;
    }
 
    if(dp[x] != -1) {
        return dp[x];
    }
 
    long long ans = 0;
 
    for(int i = 0; i < n; i++) {
        long long temp = solve(a, x - a[i]);
 
        ans = (ans + temp) % MOD;
    }
 
    return dp[x] = ans;
}
 
int main() {
    cin >> n >> x;
 
    vector<long long> a(n);
 
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
 
    dp.assign(x + 1, -1);
 
    cout << solve(a, x) << "\n";
}