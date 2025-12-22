#include <bits/stdc++.h>
using namespace std;

void solve(){
    long long k;
    cin >> k;

    long long threshould = 9; // 9 * mul * length
    long long length = 1;
    long long starter_number = 1;
    long long multiplyer = 1;
    while (k > threshould){
        k -= threshould;
        starter_number *= 10;
        multiplyer *= 10;
        length++;
        threshould = 9 * multiplyer * length;
    }

    long long val = (k-1)/length + starter_number;
    
    string s = to_string(val);
    cout << s[(k - 1) % length] << "\n";

}

int main (){

    ios::sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;
    for (auto t{0}; t < T; t++){
        solve();
    }   

    return 0;
}