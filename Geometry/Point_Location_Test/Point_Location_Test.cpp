/*
 * Problem Name: Point_Location_Test
 * Language: C++
 * Category: Geometry
 * Date: 2026-09-04
 */

#include<bits/stdc++.h>
using namespace std;
 
int main(){
    int tt;
    cin >> tt;
    while(tt--){
        long long x1, y1, x2, y2, x3, y3;
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
    if(((x2 - x1) * (y3 - y1)) == ((x3 - x1) * (y2 - y1))){
        cout << "TOUCH" << "\n";
    }
    else if(((x2 - x1) * (y3 - y1)) > ((x3 - x1) * (y2 - y1))){
        cout << "LEFT" << "\n";
    }
    else{
        cout << "RIGHT" << "\n";
    }
    }
    
}