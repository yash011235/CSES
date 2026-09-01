/*
 * Problem Name: Apartments
 * Language: C++
 * Category: Sorting_and_Searching
 * Date: 2026-09-01
 */

#include <bits/stdc++.h>
using namespace std;
 
int main() {
    long long n, m, k;
    cin >> n >> m >> k;
    vector<long long>a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    vector<long long>b(m);
    for(int i = 0; i < m; i++){
        cin >> b[i];
    }
    int ans = 0;
    int j = 0;
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    for(int i = 0; i < n; i++){
        int mn = a[i] - k;
        int mx = a[i] + k;
        int idx = lower_bound(b.begin() + j, b.end(), mn) - b.begin();
        if(idx < m && b[idx] <= mx){
            ans++;
            j = idx + 1;
        }
    }
    cout << ans << "\n";
}