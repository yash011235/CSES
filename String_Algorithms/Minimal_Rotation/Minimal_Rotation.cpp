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
    string t = s + s;
    int i = 0;
    int j = 1;
    int k = 0;
    int n = s.length();
    while(i < n && j < n && k < n){
        if(t[i + k] == t[j + k]){
            k++;
        }
        else if(t[i + k] > t[j + k]){
            i = i + k + 1;
            if(i == j){
                i++;
            }
            k = 0;
        }
        else{
            j = j + k + 1;
            if(i == j){
                j++;
            }
            k = 0;
        }
    }
    
    int start = min(i, j);
    
    string ans = t.substr(start, n);
    cout << ans << "\n";
}