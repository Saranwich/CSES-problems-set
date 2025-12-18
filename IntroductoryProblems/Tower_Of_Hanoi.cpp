#include<bits/stdc++.h>
using namespace std;

int get_num_from_base(map<vector<int>*,int>& maper, vector<int>& base){
    return maper[&base];
}

void move_n_layer (int n, vector<int>& source, vector<int>& target, vector<int>& rest, vector<pair<int,int>>& moves, size_t* move_counter, map<vector<int>*,int>& maper){

    pair<int,int> opr;

    if (n == 1) {
        target.push_back(source.back());
        source.pop_back();
        (*move_counter)++;
        opr.first = get_num_from_base(maper, source);
        opr.second = get_num_from_base(maper, target);
        moves.push_back(opr);
        return;
    }

    move_n_layer(n-1,source, rest, target, moves, move_counter, maper);
    target.push_back(source.back());
    source.pop_back();
    (*move_counter)++;
    opr.first = get_num_from_base(maper, source);
    opr.second = get_num_from_base(maper, target);
    moves.push_back(opr);
    move_n_layer(n-1,rest, target, source, moves, move_counter, maper);

}

int main (){

    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    vector<int> A(n);
    iota(A.rbegin(), A.rend(), 1);

    vector<int> B; B.reserve(n);
    vector<int> C; C.reserve(n);
    vector<pair<int,int>> moves; moves.reserve(66535);
    map<vector<int>*,int> bases_map = {{&A,1},{&B,2},{&C,3}};
    size_t move_counter = 0;

    move_n_layer(n,A,C,B, moves, &move_counter, bases_map);

    cout << move_counter << endl;
    for (auto p : moves){
        cout << p.first << " " << p.second << endl;
    }
}   