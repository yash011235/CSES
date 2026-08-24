/*
 * Problem Name: Two_Knights
 * Language: C++
 * Category: Introductory_Problems
 * Date: 2026-08-24
 */

#include<bits/stdc++.h>
using namespace std;
 
int main(){
    int n;
    cin >> n;
    for(int k = 1; k <= n; k++){
        cout << ((1LL * k * k * (k - 1LL) * (k + 1LL)) / 2) - (1LL * 4 * (k - 1LL) * (k - 2LL)) << "\n";
    }
}