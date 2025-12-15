#include <bits/stdc++.h>

using namespace std;

int main (){

    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    int v = 5;
    int counter = 0;
    while (v <= n){
        counter += (n/v);
        v *= 5;
    }
    cout << counter << endl;
    return 0;
}