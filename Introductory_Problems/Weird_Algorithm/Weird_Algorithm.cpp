/*
 * Problem Name: Weird_Algorithm
 * Language: C++
 * Category: Introductory_Problems
 * Date: 2026-08-24
 */

#include<bits/stdc++.h>
using namespace std;
 
int main(){
    long long n;
    cin >> n;
    while(n != 1){
        cout << n << " ";
        if(n % 2 == 0){
            n = n/2;
        }
        else{
            n = (3 * n) + 1;
        } 
    }
    cout << n << "\n";
}