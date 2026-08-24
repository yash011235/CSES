/*
 * Problem Name: Permutations
 * Language: C++
 * Category: Introductory_Problems
 * Date: 2026-08-24
 */

#include<bits/stdc++.h>
using namespace std;
 
int main(){
    int n;
    cin >> n;
    if(n == 1){
        cout << n << "\n";
    }
    else if(n == 2 || n == 3){
        cout << "NO SOLUTION" << "\n";
    }
    // n = 4
    // 2 4 1 3
    // n = 5
    // 2 4 1 3 5
    // n = 6
    // 2 4 6 1 3 5
    else{
        int curr = 2;
        while(curr <= n){
            cout << curr << " ";
            curr += 2;
        }
        curr = 1;
        while(curr <= n){
            cout << curr << " ";
            curr += 2;
        }
    }
    
}