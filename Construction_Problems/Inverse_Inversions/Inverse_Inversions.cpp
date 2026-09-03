/*
 * Problem Name: Inverse_Inversions
 * Language: C++
 * Category: Construction_Problems
 * Date: 2026-09-03
 */

#include <iostream>
#include <vector>
 
using namespace std;
 
int main() {
    long long n, k;
    cin >> n >> k;
    vector<int>a(n);
    int left = 1;
    int right = n;
    for(int i = 0; i < n; i++){
        if(k >= (n - i - 1)){
            k -= (n - i - 1);
            a[i] = right;
            right--;
        }
        else{
            a[i] = left;
            left++;
        }
    }
    for(int i = 0; i < n; i++){
        cout << a[i] << " ";
    }
    cout << "\n";
 
    return 0;
}