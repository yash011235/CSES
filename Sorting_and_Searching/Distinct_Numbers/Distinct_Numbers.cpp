/*
 * Problem Name: Distinct_Numbers
 * Language: C++
 * Category: Sorting_and_Searching
 * Date: 2026-09-01
 */

#include<bits/stdc++.h>
using namespace std;
 
int main(){
    int n;
    cin >> n;
    vector<long long>a(n);
    unordered_map<long long, int>mp;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        mp[a[i]]++;
    }
    cout << mp.size() << "\n";
}