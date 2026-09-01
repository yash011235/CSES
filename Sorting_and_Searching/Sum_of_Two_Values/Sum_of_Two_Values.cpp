/*
 * Problem Name: Sum_of_Two_Values
 * Language: C++
 * Category: Sorting_and_Searching
 * Date: 2026-09-01
 */

#include <bits/stdc++.h>
using namespace std;
 
int main() {
    int n;
    cin >> n;
    long long x;
    cin >> x;
    vector<pair<int, long long>>a;
    for(int i = 0; i < n; i++){
        long long num;
        cin >> num;
        a.push_back({num, i + 1});
    }
    int i = 0;
    int j = n - 1;
    sort(a.begin(), a.end());
    while(i < j){
        long long sum = a[i].first + a[j].first;
        if(sum == x){
            cout << a[i].second << " " << a[j].second << "\n";
            return 0;
        }
        else if(sum > x){
            j--;
        }
        else{
            i++;
        }
    }
    cout << "IMPOSSIBLE" << "\n";
}