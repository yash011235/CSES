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
        // 1 2 3 4 5 6 7 8
        // 1 3 6 8   18 
        // 2 4 5 7   18
        if(n % 2 == 0){
            int swaps = n / 2;
            vector<int>a;
            vector<int>b;
            for(int i = 1; i <= swaps; i++){
                if(i % 2 == 1)
                a.push_back(i);
                else
                b.push_back(i);
            }
            for(int i = swaps + 1; i <= n; i++){
                if(i % 2 == 0)
                a.push_back(i);
                else
                b.push_back(i);
            }
            cout << "YES\n";
            cout << a.size() << "\n";
            for(int &x : a){
                cout << x << " ";
            }
            cout << "\n";
            cout << b.size() << "\n";
            for(int &x : b){
                cout << x << " ";
            }
            cout << "\n";
        }
        else{
            // n = 7
            // 1 2 3 4 5 6 7
            //  1 3 5 7 ->16
            //  2 4 6    -> 12
            // increase (n + 1)/2 
            // 1 2 3 4 5 6 7
            // T F T F T F T
            //dec = 4
            vector<long long>inSetOne(n + 1, false);
            for(int i = 1; i <= n; i++){
                if(i % 2 == 1){
                    inSetOne[i] = true;
                }
            }
            int decrease = (n + 1) / 4;
            for(int i = 1; i <= n; i++){
                if(decrease == 0){
                    break;
                }
                if(inSetOne[i] && i > 1){
                    inSetOne[i] = false;
                    inSetOne[i - 1] = true;
                    decrease--;
                }
            }
            vector<int>a;
            vector<int>b;
            for(int i = 1; i <= n; i++){
                if(inSetOne[i]){
                    a.push_back(i);
                }
                else{
                    b.push_back(i);
                }
            }
            cout << "YES\n";
            cout << a.size() << "\n";
            for(int &x : a){
                cout << x << " ";
            }
            cout << "\n";
            cout << b.size() << "\n";
            for(int &x : b){
                cout << x << " ";
            }
            cout << "\n";
        }
    }
}