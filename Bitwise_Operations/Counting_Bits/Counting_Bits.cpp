/*
 * Problem Name: Counting_Bits
 * Language: C++
 * Category: Bitwise_Operations
 * Date: 2026-09-03
 */

#include<bits/stdc++.h>
using namespace std;
 
int main(){
    long long n;
    cin >> n;
    int ans = 0;
    for(int i = 1; i <= n; i++){
        ans += __builtin_popcount(i);
    }
    cout << ans << "\n";
}