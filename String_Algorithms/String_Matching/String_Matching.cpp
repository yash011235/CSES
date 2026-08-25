/*
 * Problem Name: String_Matching
 * Language: C++
 * Category: String_Algorithms
 * Date: 2026-08-25
 */

#include<bits/stdc++.h>
using namespace std;
 
int main(){
    string t, p;
    int cnt = 0;
    cin >> t >> p;
    int n = t.size();
    int m = p.size();
    for(int i = 0; i <= (n - m); i++){
        bool flag = true;
        for(int j = 0; j < m; j++){
            if(t[i + j] != p[j]){
                flag = false;
            }
        }
        if(flag){
            cnt++;
        }
    }
    cout << cnt << "\n";
}