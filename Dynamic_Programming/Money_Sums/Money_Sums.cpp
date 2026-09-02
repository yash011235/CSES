/*
 * Problem Name: Money_Sums
 * Language: C++
 * Category: Dynamic_Programming
 * Date: 2026-09-02
 */

#include<bits/stdc++.h>
using namespace std;
set<int>sums;
void solve(vector<int>&a, int idx, int n, int curr){
    if(idx == n){
        sums.insert(curr);
        return;
    }
    sums.insert(curr);
    solve(a, idx + 1, n, curr + a[idx]);
    solve(a, idx + 1, n, curr);
    return;
}
int main(){
    int n;
    cin >> n;
    vector<int>a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    solve(a, 0, n, 0);
    cout << sums.size() - 1 << "\n";
    auto itr = sums.begin();
    itr++;
    while(itr != sums.end()){
        cout << *itr << " ";
        itr++;
    }
}