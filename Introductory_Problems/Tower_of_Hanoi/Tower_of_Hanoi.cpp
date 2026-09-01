/*
 * Problem Name: Tower_of_Hanoi
 * Language: C++
 * Category: Introductory_Problems
 * Date: 2026-09-01
 */

#include<bits/stdc++.h>
using namespace std;
 
void solve(int n, int from, int to){
    if(n == 0){
        return;
    }
    cout << from << " " << to << "\n";
}
 
int solve2(int n){
    if(n == 1){
        return 1;
    }
    return (2 * (n - 1)) + solve2(n - 1);
}
 
int main(){
    int n;
    cin >> n;
    int ans = solve2(n);
    cout << ans << "\n";
    while(n >= 1){
        solve(n - 1, 1, 2);
        solve(1, 1, 3);
        if(n - 1 == 1){
            cout << 2 << " " << 3 << "\n";
            return 0;
        }
        else{
            solve(n - 1, 2, 1);
        }
        n--;
    }
}