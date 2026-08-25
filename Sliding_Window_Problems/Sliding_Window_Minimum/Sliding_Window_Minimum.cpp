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
    vector<long long>arr;
    long long x, a, b, c;
    cin >> x >> a >> b >> c;
    arr.push_back(x);
    //O(n)
    for(long long i = 1; i < n; i++){
        long long num = ((arr[i - 1] * a) + b) % c;
        arr.push_back(num);
    }
    deque<long long>dq; //stores indices of values in increasing order
    long long ans = 0;
    for(long long i = 0; i < n; i++){
        //1. remove elements outside current window
        while(!dq.empty() && dq.front() <= i - k){
            dq.pop_front();
        }
        //2. remove larger elements from the back
        while(!dq.empty() && arr[dq.back()] >= arr[i]){
            dq.pop_back();
        }
        //3. add curren element
        dq.push_back(i);
        if(i >= (k - 1)){
            ans = ans ^ arr[dq.front()];
        } 
    }
    cout << ans << "\n";
}