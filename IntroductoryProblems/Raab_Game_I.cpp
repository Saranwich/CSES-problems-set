#include <bits/stdc++.h>
using namespace std;

void show_game(){
    int n, a, b;
    cin >> n >> a >> b;
    int draw = n-a-b;
    
    if (a == 0 && b == 0){
        cout << "YES\n";
        for (int x = 0; x < 2; x++){
            for (int i = 1; i <= n; i++){
                cout << i << " ";
            } 
            cout << "\n" ;
        }
        return;
    }
    if ((a + b > n) || ((a == 0 && b != 0) || (b == 0 && a != 0)) || (((n-draw & 1) && (a==b)))){
        cout << "NO" << "\n";
        return;
    }


    vector<int> a_cards(n,0); iota(a_cards.begin(),a_cards.end(),1);
    vector<int> b_cards;b_cards.reserve(n);

    //make it tie
    for (int i = 1; i <= draw; i++){
        b_cards.push_back(i);
    }

    for (int i = 0; i < n-draw; i++){
        b_cards.push_back(((i+a) % (n- draw)) + draw+1);
    }

    //output
    cout << "YES\n";
    for (int x : a_cards){
        cout << x << " ";
    }
    cout << "\n";
    for (int x : b_cards){
        cout << x << " ";
    }
    cout << "\n";
}

int main (){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;
    for (int t = 0 ; t < T; t++){
        show_game();
    }

    return 0;
}