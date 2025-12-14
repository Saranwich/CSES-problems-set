#include <bits/stdc++.h>

using namespace std;

int main (){

    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    long long a = 2;
    long long m = 1e9 + 7;
    long long res = 1;

    while (n > 1) {
        if (n & 1) {
            res = res * a;
            res %= m;
        }
        a *= a;
        a %= m;
        n/=2;   
    }

    cout << (res * a) % m;

    return 0;
}