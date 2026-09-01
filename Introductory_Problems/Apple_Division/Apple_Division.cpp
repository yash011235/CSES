/*
 * Problem Name: Apple_Division
 * Language: C++
 * Category: Introductory_Problems
 * Date: 2026-09-01
 */

#include<bits/stdc++.h>
using namespace std;
 
int main(){
    int n;
    cin >> n;
    vector<long long>a(n);
    long long total = 0;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        total += a[i];
    }
    long long s1 = 0;
    long long mn = INT_MAX;
    for(int i = 0; i < n; i++){
        s1 = 0;
        for(int j = i; j < n; j++){
            s1 += a[i];
            if((2 * s1) > total)
            mn = min(mn, (2 * s1) - total);
            else
            mn = min(mn, total - (2 * s1));
        }
    }
    cout << mn << "\n";
}