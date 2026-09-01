/*
 * Problem Name: Book_Shop
 * Language: C++
 * Category: Dynamic_Programming
 * Date: 2026-09-01
 */

#include <bits/stdc++.h>
using namespace std;
 
int main() {
    int n, x;
    cin >> n >> x;
 
    vector<int> price(n), pages(n);
 
    for (int i = 0; i < n; i++)
        cin >> price[i];
 
    for (int i = 0; i < n; i++)
        cin >> pages[i];
 
    vector<int> dp(x + 1, 0);
 
    for (int i = 0; i < n; i++) {
        for (int a = x; a >= price[i]; a--) {
            dp[a] = max(dp[a],
                        pages[i] + dp[a - price[i]]);
        }
    }
 
    cout << dp[x] << '\n';
}