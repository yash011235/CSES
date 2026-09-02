/*
 * Problem Name: Elevator_Rides
 * Language: C++
 * Category: Dynamic_Programming
 * Date: 2026-09-02
 */

#include<bits/stdc++.h>
using namespace std;
 
int main(){
    int n;
    cin >> n;
    long long x;
    cin >> x;
    vector<long long>a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
   vector<pair<int, long long>> dp(1 << n, {n + 1, 0});
    dp[0] = {1, 0};
    for(int mask = 0; mask < (1 << n); mask++){
        for(int i = 0; i < n; i++){
            if((mask & (1 << i)) == 0){
                int newmask = mask | (1 << i);
                int rides = dp[mask].first;
                long long weight = dp[mask].second;
 
                if((1LL * a[i]) + weight <= x){
                    weight += (1LL * a[i]);
                }
                else{
                    weight = 1LL * a[i];
                    rides++;
                }
                dp[newmask] = min(dp[newmask], {rides, weight});
            }
        }
    }
    cout << dp[(1 << n) - 1].first << "\n";
}