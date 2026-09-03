/*
 * Problem Name: Inverse_Inversions
 * Language: C++
 * Category: Construction_Problems
 * Date: 2026-09-03
 */

#include<bits/stdc++.h>
using namespace std;
 
void rotate(vector<int>&a, int num) {
	int curr = num + 1;
	int n = a.size();
	for(int i = 0; i < (n - num); i++) {
		a[i] = curr;
		curr++;
	}
	a[n - num] = num;
	for(int i = n - num + 1; i < n; i++) {
		a[i] = a[i - 1] - 1;
	}
}
 
void rotate2(vector<int>&a, int rem, int num) {
	for(int i = 0; i < rem; i++) {
		a[i] = a[i + 1];
	}
	a[rem] = num;
}
 
int main() {
	int n, k;
	cin >> n >> k;
	vector<int>a(n);
	for(int i = 0; i < n; i++) {
		a[i] = (i + 1);
	}
    if(k == (n * (n - 1)) / 2){
        for(int i = n; i >= 1; i--){
            cout << i << " ";
        }
        cout << "\n";
        return 0;
    }
	for(int x = 1; x <= ((n - 1) * n) / 2; x++) {
		if(x > k) {
			break;
		}
		else if(x == k) {
			int div = (x + n - 2)/ (n - 1);
			int rem = x % (n - 1);
            if(rem == 0){
                rem = (n - 1);
            }
			for(int num = 1; num < div; num++) {
				rotate(a, num);
			}
 
			rotate2(a, rem, div);
		}
	}
	for(int &e : a) {
		cout << e << " ";
	}
 
}