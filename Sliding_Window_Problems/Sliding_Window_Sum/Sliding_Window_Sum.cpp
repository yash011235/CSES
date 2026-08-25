/*
 * Problem Name: Sliding_Window_Sum
 * Language: C++
 * Category: Sliding_Window_Problems
 * Date: 2026-08-25
 */

#include<bits/stdc++.h>
using namespace std;
 
int main(){
    long long n, k;
    cin >> n >> k;
    vector<int>arr;
    long long x, a, b, c;
    cin >> x >> a >> b >> c;
    arr.push_back(x);
    //O(n)
    for(long long i = 1; i < n; i++){
        long long num = ((arr[i - 1] * a) + b) % c;
        arr.push_back(num);
    }
    long long sum = 0;
    //O(k)
    for(long long i = 0; i < k; i++){
        sum += 1LL * arr[i];
    }
    long long ans = sum;
    //O(n - k)
    for(long long i = k; i < n; i++){
        long long newsum = sum + arr[i] - arr[i - k];
        sum = newsum;
        ans = ans ^ newsum;
    }
    cout << ans << "\n";
}