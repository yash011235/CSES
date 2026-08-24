/*
 * Problem Name: Two_Sets
 * Language: C++
 * Category: Introductory_Problems
 * Date: 2026-08-24
 */

#include<bits/stdc++.h>
using namespace  std;
 
int main(){
    long long n;
    cin >> n;
    long long sum = (n * (n + 1)) / 2;
    if(sum % 2 == 1){
        cout << "NO\n";
    }
    else{
        long long target = sum / 2;
        vector<int>set1;
        vector<int>set2;
        for(long long i = n; i >= 1; i--){
            if(i <= target){
                set1.push_back(i);
                target -= i;
            }
            else{
                set2.push_back(i);
            }
        }
 
    cout << "YES\n";
 
    cout << set1.size() << "\n";
    for (int x : set1)
        cout << x << " ";
    cout << "\n";
 
    cout << set2.size() << "\n";
    for (int x : set2)
        cout << x << " ";
    cout << "\n";
    }
}