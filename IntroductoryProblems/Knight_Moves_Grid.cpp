#include <bits/stdc++.h>
using namespace std;

int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    vector<pair<int,int>> knight_moves = {
        pair<int,int>{2,1},
        pair<int,int>{2,-1},
        pair<int,int>{-2,1},
        pair<int,int>{-2,-1},
        pair<int,int>{1,2},
        pair<int,int>{-1,2},
        pair<int,int>{1,-2},
        pair<int,int>{-1,-2},
    };
    queue<pair<int,int>> q;q.push(pair<int,int> {0,0});
    vector<vector<int>> board(n,vector<int> (n,-1));
    board[0][0] = 0;

    while (!(q.empty())){
        pair<int,int> p = q.front();
        q.pop();

        int r = p.first;
        int c = p.second;

        for (auto m : knight_moves){
            int nr = r + m.first;
            int nc = c + m.second;

            if ((nr < 0) || (nr >= n) || (nc < 0) || (nc >= n)) continue;
            if (board[nr][nc] != -1) continue;
            q.push(pair<int,int> {nr,nc});
            board[nr][nc] = board[r][c] + 1 ;
        }

    }

    for (auto i : board){
        for (auto j : i){
            cout << j << " ";
        }
        cout << "\n";
    }
    return 0;
}