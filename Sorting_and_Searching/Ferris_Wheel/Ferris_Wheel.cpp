/*
 * Problem Name: Ferris_Wheel
 * Language: C++
 * Category: Sorting_and_Searching
 * Date: 2026-09-01
 */

#include <bits/stdc++.h>
using namespace std;
 
int main() {
    int n, x;
    cin >> n >> x;
 
    vector<int> a(n);
 
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
 
    sort(a.begin(), a.end());
 
    int i = 0;
    int j = n - 1;
    int ans = 0;
 
    while (i < j) {
        if (a[i] + a[j] <= x) {
            i++;
            j--;
        } else {
            j--;
        }
 
        ans++;
    }
    if(i == j){
        ans++;
    }
    cout << ans << '\n';
 
    return 0;
}