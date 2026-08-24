/*
 * Problem Name: Missing_Number
 * Language: C++
 * Category: Introductory_Problems
 * Date: 2026-08-24
 */

#include<bits/stdc++.h>
using namespace std;
 
int main(){
    long long n;
    cin >> n;
    long long sum = 0;
    for(int i = 1; i < n; i++){
        int x;
        cin >> x;
        sum += x;
    }
    long long total = (n * (n + 1)) / 2;
    cout << total - sum << "\n";
}