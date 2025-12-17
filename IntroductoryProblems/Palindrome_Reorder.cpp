#include<bits/stdc++.h>

using namespace std;

int main (){

    ios::sync_with_stdio(0);
    cin.tie(0);

    string s;
    cin >> s;

    map<char,int> counter;
    for(char c : s){
        counter[c]++;
    }

    string middle = "";

    for (auto &pair : counter){
        
        if (pair.second & 1){
            if (middle.length() == 0) {
                middle = string(1, pair.first);
                pair.second -=1;
            }
            else {
                cout << "NO SOLUTION";
                return 0;
            }
        }
    }
    string palindrome_sub_string = "";
    for (auto const& pair : counter){
        palindrome_sub_string += string(pair.second / 2, pair.first);
    }
    string r_palindrome_sub_string = palindrome_sub_string;
    reverse(r_palindrome_sub_string.begin(),r_palindrome_sub_string.end());
    s = palindrome_sub_string + middle + r_palindrome_sub_string;

    cout << s;

    return 0;
}