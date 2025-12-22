#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n,m;
    cin >> n >> m;
    
    //input
    vector<vector<char>> grid(n,vector<char> (m,'A'- 1));
    for (auto i{0}; i < n; i++){
        for(auto j{0}; j < m ; j++){
            cin >> grid[i][j] ;
        }
    }

    for (auto i{0}; i < n; i++){
        for(auto j{0}; j < m ; j++){
            char current = grid[i][j];
            char top = (i > 0)? grid[i-1][j] : '@';
            char left = (j > 0)? grid[i][j-1] : '@';

            for (char c : {'A','B','C','D'}){
                if (c != current && c != top && c != left) {
                    grid[i][j] = c;
                    break;
                }
            }
        }
    }

    //output
    for (auto i : grid){
        for (auto j : i){
            cout << j ;
        }
        cout << "\n";
    }
    
}

int main (){

    ios::sync_with_stdio(0);
    cin.tie(0);

    solve();

    return 0;
}