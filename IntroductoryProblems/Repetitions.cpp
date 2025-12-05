#include<bits/stdc++.h>

using namespace std;

int main (){
    ios::sync_with_stdio(0);
    cin.tie(0);

    string s;
    cin >> s;

    int l = 0;
    if (s.length() == 1){
        cout << 1 << endl;
        return 0;
    }

    int r = 1;
    int max_freq = 1;
    int current_freq = 1;

    while (r <= (int)(s.length() - 1)){
        if (s[l] == s[r]){
            r++;
            current_freq++;
        }else{
            max_freq = max(max_freq, current_freq);
            current_freq = 1;
            l = r;
            r++;
        }
    }
    max_freq = max(max_freq, current_freq);
    cout << max_freq << endl;
    return 0;
}