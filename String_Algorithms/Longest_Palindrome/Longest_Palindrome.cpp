/*
 * Problem Name: Longest_Palindrome
 * Language: C++
 * Category: String_Algorithms
 * Date: 2026-09-01
 */

#include <bits/stdc++.h>
using namespace std;
 
int main() {
    string s;
    cin >> s;
    string t = s;
    reverse(t.begin(), t.end());
    int n = s.size();
    int m = t.size();
 
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
 
    int maxLen = 0;
    int endIndex = 0;
 
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
 
            if (s[i - 1] == t[j - 1]) {
                dp[i][j] = 1 + dp[i - 1][j - 1];
 
                if (dp[i][j] > maxLen) {
                    maxLen = dp[i][j];
                    endIndex = i;
                }
            }
        }
    }
 
    string ans = s.substr(endIndex - maxLen, maxLen);
 
    cout << ans << "\n";
}