/*
 * Problem Name: Sliding_Window_Sum
 * Language: C++
 * Category: Sliding_Window_Problems
 * Date: 2026-08-25
 */

#include<bits/stdc++.h>
using namespace std;
 
int main(){
    int n, k;
    cin >> n >> k;
    vector<int>arr;
    int x, a, b, c;
    cin >> x >> a >> b >> c;
    arr.push_back(x);
    for(int i = 1; i < n; i++){
        int num = ((arr[i - 1] * a) + b) % c;
        arr.push_back(num);
    }
    int sum = 0;
    for(int i = 0; i < k; i++){
        sum += arr[i];
    }
    int ans = sum;
    for(int i = k; i < n; i++){
        int newsum = sum + arr[i] - arr[i - k];
        sum = newsum;
        ans = ans ^ newsum;
    }
    cout << ans << "\n";
}