/*
 * Problem Name: Finding_Patterns
 * Language: C++
 * Category: String_Algorithms
 * Date: 2026-08-25
 */

#include<bits/stdc++.h>
using namespace std;
 
bool search(string &txt, string &pat){
    int n = txt.size();
    int m = pat.size();
    vector<int>lps(m);
    lps[0] = 0;
    int i = 1;
    int len = 0;
    while(i < m){
        if(pat[i] == pat[len]){
            len++;
            lps[i] = len;
            i++;
        }
        else{
            if(len != 0){
                len = lps[len - 1];
            }
            else{
                lps[i] = 0;
                i++;
            }
        }
    }
 
    i = 0;
    int j = 0;
    while(i < n){
        if(txt[i] == pat[j]){
            i++;
            j++;
            if(j == m){
                return true;
            }
        }
        else{
            if(j != 0){
                j = lps[j - 1];
            }
            else{
                i++;
            }
        }
    }
    return false;
}
 
 
 
int main(){
    string txt;
    cin >> txt;
    int k;
    cin >> k;
    while(k--){
        string pat;
        cin >> pat;
        if(search(txt, pat)){
            cout << "YES\n";
        }
        else{
            cout << "NO\n";
        }
    }
}