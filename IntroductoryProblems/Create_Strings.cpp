#include <bits/stdc++.h>

using namespace std;

void printv(vector<int>& vec, string name = "vec"){
    cout << "<" << name << ">: ";
    for (auto i : vec){
        cout << i << " ";
    }
    cout << endl;
}

void create_string_from(map<char,int>& char_counter,string& prev_string){
    int elements_size = 0;
    for (auto [c,f] : char_counter){
        elements_size += f;
    }
    
    if (elements_size == 1) {
        for (auto [c,f] : char_counter){
            if (f <= 0) continue;
            cout << prev_string << c << endl;
            return;
        }
            
    }

    for (auto [c , f] : char_counter){
        if (f <= 0) continue;
        char_counter[c]-=1;
        prev_string += c;
        create_string_from(char_counter,prev_string);
        prev_string.pop_back();
        char_counter[c]+=1;
    };
}

int main (){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    map<int,int> fac = {{0,1},{1,1},{2,2},{3,6},{4,24},{5,120},{6,720},{7,5040},{8,40320}}; 
    string s;
    cin >> s;
    
    int permutation_with_duplicate = fac[s.size()];

    map<char,int> char_counter;
    for (auto i : s){
        char_counter[i]++;
    }
    for (auto [a,b] : char_counter){
        if (b > 1) permutation_with_duplicate /= fac[b];
    }
    cout << permutation_with_duplicate << "\n";

    s = "";
    create_string_from(char_counter, s);
    


    return 0;
}