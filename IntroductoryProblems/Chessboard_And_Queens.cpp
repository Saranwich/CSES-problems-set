#include <bits/stdc++.h>

using namespace std;

void place(int r, vector<int>& col, vector<int>& diag1, vector<int>& diag2, vector<string>& board, int *counter){
    
    //already place 0-7 (8) row
    if (r == 8){
        (*counter) += 1;
        return;
    }

    for (int c = 0; c < 8; c++){
        if (col[c] || board[r][c] == '*' || diag1[r+c] || diag2[r-c+7]){
            continue;
        }

        col[c] = 1;
        diag1[r+c] = 1;
        diag2[r-c+7] = 1;

        place(r+1,col,diag1,diag2, board,counter);

        col[c] = 0;
        diag1[r+c] = 0;
        diag2[r-c+7] = 0;
    }
}

int main (){

    ios::sync_with_stdio(0);
    cin.tie(0);

    vector<int> col(8,0);
    vector<int> diag1(15,0);
    vector<int> diag2(15,0);
    vector<string> inp(8);
    for (int i = 0; i < 8; i++){
        cin >> inp[i];
    }

    int ans = 0;
    place(0, col, diag1, diag2, inp, &ans);
    cout << ans << endl;
    
    return 0;
}