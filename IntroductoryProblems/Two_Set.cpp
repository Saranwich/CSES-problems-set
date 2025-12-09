#include <bits/stdc++.h>

using namespace std;

int main (){

    ios::sync_with_stdio(0);
    cin.tie(0);

    long long n;
    cin >> n;

    if (n % 4 == 1 || n <= 2 || n % 4 == 2){
        cout << "NO" << endl;
        return 0;
    }

    set<int> a;
    set<int> b;
    long long remain = (n*(n+1)) / 4;
    for (int i = n; i >= 1; i--){
        if (i <= remain){
            a.insert(i);
            remain -= i;
        } 
        else b.insert(i);
    }

    cout << "YES" << endl;
    cout << a.size() << endl;
    for (auto i : a) {
        cout << i << " ";
    }
    cout << "\n";
    cout << b.size() << endl;
    for (auto i : b) {
        cout << i << " ";
    }
    cout << "\n";

    return 0;
}