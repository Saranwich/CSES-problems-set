#include <bits/stdc++.h>

using namespace std;

int main (){

    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;

    if (n == 1) {
        cout << "1" << endl;
        return 0;
    }

    if (n <= 3) {
        cout << "NO SOLUTION" << endl;
        return 0;
    }
    string odd_string = "1 3";
    string even_string = "2";

    for (int i = 2; i <= n/2; i++){
        even_string += " " + to_string(i*2);
        if (i*2+1 <= n) odd_string += " " + to_string(i*2+1);
        
    }

    cout << even_string << " " << odd_string << endl;
    
    return 0;
}