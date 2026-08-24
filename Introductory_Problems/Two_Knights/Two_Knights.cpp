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
        cout << ((k * k * (k - 1) * (k + 1)) / 2) - (4 * (k - 1) * (k - 2)) << "\n";
    }
}