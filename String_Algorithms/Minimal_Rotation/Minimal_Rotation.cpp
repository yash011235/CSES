/*
 * Problem Name: Minimal_Rotation
 * Language: C++
 * Category: String_Algorithms
 * Date: 2026-09-01
 */

#include <bits/stdc++.h>
using namespace std;
 
int main() {
    string s;
    cin >> s;
 
    int n = s.length();
    string ans = s;
 
    for (int i = 0; i < n - 1; i++) {
        rotate(s.begin(), s.end() - 1, s.end());
        ans = min(ans, s);
    }
 
    cout << ans << "\n";
}