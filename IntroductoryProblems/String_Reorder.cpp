#include<bits/stdc++.h>

using namespace std;

int get_max(const vector<int>& count) {
    int max_val = 0;
    for (int c : count) {
        if (c > max_val) max_val = c;
    }
    return max_val;
}

int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0);

    string s;
    cin >> s;

    int n = s.length();
    vector<int> count(26, 0);

    for (char c : s) {
        count[c - 'A']++;
    }

    if (get_max(count) > (n + 1) / 2) {
        cout << -1;
        return 0;
    }

    string result = "";
    int last_char = -1;

    for (int i = 0; i < n; i++) {
        int remaining_len = n - 1 - i;
        
        for (int j = 0; j < 26; j++) {
            if (count[j] > 0 && j != last_char) {
                count[j]--;
                
                int current_max = get_max(count);
                int limit = (remaining_len + 1) / 2;

                if (current_max <= limit) {
                    result += (char)('A' + j);
                    last_char = j;
                    break; 
                }

                count[j]++;
            }
        }
    }

    cout << result;
    return 0;
}