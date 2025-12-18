#include<bits/stdc++.h>
using namespace std;

void remove_n_layer (int n, int source, int target, int buffer){
    if (n == 1){
        cout << source << " " << target << "\n";
        return ;
    }
    remove_n_layer(n-1, source, buffer, target);
    cout << source << " " << target << "\n";
    remove_n_layer(n-1, buffer, target, source);
}

int main (){

    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    cout << (1 << n) -1 << endl;
    remove_n_layer(n,1,3,2);
    return 0;
}