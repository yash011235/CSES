/*
 * Problem Name: Inverse_Inversions
 * Language: C++
 * Category: Construction_Problems
 * Date: 2026-09-03
 */

#include <bits/stdc++.h>
using namespace std;
 
void rotate(vector<long long>& a, long long num) {
    long long curr = num + 1;
    long long n = a.size();
 
    for(long long i = 0; i < n - num; i++) {
        a[i] = curr;
        curr++;
    }
 
    a[n - num] = num;
 
    for(long long i = n - num + 1; i < n; i++) {
        a[i] = a[i - 1] - 1;
    }
}
 
void rotate2(vector<long long>& a, long long rem, long long num) {
    for(long long i = 0; i < rem; i++) {
        a[i] = a[i + 1];
    }
 
    a[rem] = num;
}
 
int main() {
    long long n, k;
    cin >> n >> k;
 
    vector<long long> a(n);
 
    for(long long i = 0; i < n; i++) {
        a[i] = i + 1;
    }
 
    if(k == (n * (n - 1)) / 2) {
        for(long long i = n; i >= 1; i--) {
            cout << i << " ";
        }
        cout << "\n";
        return 0;
    }
 
    long long x = k;
 
    long long div = (x + n - 2) / (n - 1);
 
    long long rem = x % (n - 1);
 
    if(rem == 0) {
        rem = n - 1;
    }
 
    for(long long num = 1; num < div; num++) {
        rotate(a, num);
    }
 
    rotate2(a, rem, div);
 
    for(long long &e : a) {
        cout << e << " ";
    }
 
    cout << "\n";
 
    return 0;
}