#include <bits/stdc++.h>

using namespace std;

int main (){

    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    set<int> s;
    for (int i = 0; i < n/2+1; i++){
        s.insert({i,n-i});
    }
    int buffer;
    for (int i = 0; i < n-1; i++){
        cin >> buffer;
        s.erase(buffer - 1);
    }

    cout << *s.begin() + 1<< endl;
}