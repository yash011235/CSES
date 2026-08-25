/*
 * Problem Name: Sliding_Window_Minimum
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
    for(int i = 1; i < n; i++){
        long long num = ((a * arr[i - 1]) + b) % c;
        arr.push_back(num);
    }
    long long ans = 0;
    deque<int>dq;
    //stores indices in values in increasing order
    for(int i = 0; i < n; i++){
        while(!dq.empty() && dq.front() <= i - k){
            dq.pop_front();
        }
        while(!dq.empty() && arr[dq.back()] >= arr[i]){
            dq.pop_back();
        }
        dq.push_back(i);
        if(i >= (k - 1)){
            ans = ans ^ arr[dq.front()];
        }
    }
    cout << ans << "\n";
}