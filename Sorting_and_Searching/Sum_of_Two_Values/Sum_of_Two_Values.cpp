/*
 * Problem Name: Sum_of_Two_Values
 * Language: C++
 * Category: Sorting_and_Searching
 * Date: 2026-09-01
 */

#include <bits/stdc++.h>
using namespace std;
 
int main() {
    int n;
    cin >> n;
    long long x;
    cin >> x;
    vector<long long>a(n);
    unordered_map<long long, int>mp;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        mp[a[i]] = i + 1;
    }
    int i = 0;
    int j = n - 1;
    sort(a.begin(), a.end());
    while(i < j){
        long long sum = a[i] + a[j];
        if(sum == x){
            cout << mp[a[i]] << " " << mp[a[j]] << "\n";
            return 0;
        }
        else if(sum > x){
            j--;
        }
        else{
            i++;
        }
    }
    cout << "IMPOSSIBLE" << "\n";
}