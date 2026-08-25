/*
 * Problem Name: Sliding_Window_Xor
 * Language: C++
 * Category: Sliding_Window_Problems
 * Date: 2026-08-25
 */

#include<bits/stdc++.h>
using namespace std;
 
int main(){
    long long n, k;
    cin >> n >> k;
    long long x, a, b, c;
    cin >> x >> a >> b >> c;
    vector<long long>arr;
    arr.push_back(x);
    for(long long i = 1; i < n; i++){
        long long num = ((a * arr[i - 1]) + b) % c;
        arr.push_back(num);
    }
    long long ans = 0;
    long long l = 0;
    long long r = n - 1;
    long long mn = min(k, n - k + 1);
    vector<long long>times(n, 0);
    long long curr = 1;
    while(l <= r){
        if(curr % 2 == 0){
            times[l] = times[r] = 0;
        }
        else{
            times[l] = times[r] = 1;
        }
        curr++;
        l++;
        r--;
        if(curr > mn){
            curr = mn;
        }
    }
    for(long long i = 0; i < n; i++){
        ans ^= (times[i] * arr[i]);
    }
    cout << ans << "\n";
}