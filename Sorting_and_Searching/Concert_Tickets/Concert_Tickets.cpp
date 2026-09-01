/*
 * Problem Name: Concert_Tickets
 * Language: C++
 * Category: Sorting_and_Searching
 * Date: 2026-09-01
 */

#include <bits/stdc++.h>
using namespace std;
 
int main() {
    int n, m;
    cin >> n >> m;
 
    multiset<long long> prices;
    
    for (int i = 0; i < n; i++) {
        long long x;
        cin >> x;
        prices.insert(x);
    }
 
    for (int i = 0; i < m; i++) {
        long long maxPrice;
        cin >> maxPrice;
 
        auto it = prices.upper_bound(maxPrice);
 
        if (it == prices.begin()) {
            cout << -1 << "\n";
        } 
        else {
            --it;
            cout << *it << "\n";
            prices.erase(it);   
        }
    }
}