/*
 * Problem Name: Bit_Strings
 * Language: C++
 * Category: Introductory_Problems
 * Date: 2026-08-24
 */

#include<bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
int main(){
    long long n;
    cin >> n;
    long long ans = 1;
    while(n--){
        ans = (ans * 2) % MOD;
    }
    ans %= MOD;
    cout << ans << "\n";
}