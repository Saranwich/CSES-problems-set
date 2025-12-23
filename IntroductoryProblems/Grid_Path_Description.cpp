#include <bits/stdc++.h>
using namespace std;

void solve(vector<vector<int>>& board, string& command, int* solution_counter, int cur_row, int cur_col, int step = 0){

    if (cur_row == 7 && cur_col == 1) {
        if (step == 48) (*solution_counter)++;
        return;
    }
    
    if (step == 48) return;

    if (board[cur_row][cur_col - 1] && board[cur_row][cur_col + 1] && 
        !board[cur_row - 1][cur_col] && !board[cur_row + 1][cur_col]) return;

    if (board[cur_row - 1][cur_col] && board[cur_row + 1][cur_col] && 
        !board[cur_row][cur_col - 1] && !board[cur_row][cur_col + 1]) return;

    board[cur_row][cur_col] = 1;

    int dr[4] = {-1, 0, 1, 0};
    int dc[4] = {0, 1, 0, -1};
    char dirs[4] = {'U', 'R', 'D', 'L'};

    for (int i = 0; i < 4; i++) {
        int next_row = cur_row + dr[i];
        int next_col = cur_col + dc[i];

        if (!board[next_row][next_col]) {
            if (command[step] == '?' || command[step] == dirs[i]) {
                solve(board, command, solution_counter, next_row, next_col, step + 1);
            }
        }
    }

    board[cur_row][cur_col] = 0;
}   

int main (){

    ios::sync_with_stdio(0);
    cin.tie(0);

    string command;
    cin >> command;

    int solution_counter = 0;
    
    vector<vector<int>> board(9, vector<int>(9, 0));
    
    for (int i = 0; i < 9; i++) {
        board[0][i] = 1;
        board[8][i] = 1;
        board[i][0] = 1;
        board[i][8] = 1;
    }

    solve(board, command, &solution_counter, 1, 1);

    cout << solution_counter << endl;

    return 0 ;
}