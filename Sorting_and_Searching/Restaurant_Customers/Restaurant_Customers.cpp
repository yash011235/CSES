/*
 * Problem Name: Restaurant_Customers
 * Language: C++
 * Category: Sorting_and_Searching
 * Date: 2026-09-01
 */

#include <bits/stdc++.h>
using namespace std;
 
int main() {
    int n;
    cin >> n;
 
    vector<pair<int, int>> events;
 
    for (int i = 0; i < n; i++) {
        int l, r;
        cin >> l >> r;
 
        events.push_back({l, +1});
        events.push_back({r, -1});
    }
 
    sort(events.begin(), events.end());
 
    int active = 0;
    int maxOverlap = 0;
 
    for (auto [x, type] : events) {
        active += type;
        maxOverlap = max(maxOverlap, active);
    }
 
    cout << maxOverlap << '\n';
}