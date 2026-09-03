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
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    long long n, k;
    if (!(cin >> n >> k)) return 0;
 
    // Maximum inversions possible with n elements is n * (n - 1) / 2
    long long max_k = n * (n - 1) / 2;
    if (k < 0 || k > max_k) {
        cout << -1 << "\n";
        return 0;
    }
 
    vector<long long> result(n);
    long long left = 1, right = n;
 
    for (long long i = 0; i < n; i++) {
        long long remaining_elements = n - 1 - i;
        if (k >= remaining_elements) {
            result[i] = right;
            right--;
            k -= remaining_elements;
        } else {
            result[i] = left;
            left++;
        }
    }
 
    for (long long i = 0; i < n; i++) {
        cout << result[i] << (i == n - 1 ? "" : " ");
    }
    cout << "\n";
 
    return 0;
}