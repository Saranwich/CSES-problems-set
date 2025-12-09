#include <bits/stdc++.h>

using namespace std;

int main (){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    long long term ;
    long long all_pos, attackable;
    for (long long i = 1; i <= n; i++){
        term = i*i;
        all_pos = term * (term-1) / 2;
        attackable = 4 * (i-1) * (i-2);
        cout << all_pos - attackable << endl;
    }

    return 0;
}