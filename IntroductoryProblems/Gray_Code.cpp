#include <bits/stdc++.h>

using namespace std;

void printBinary(int num, int n) {
    for (int k = n - 1; k >= 0; k--) {
        int bit = (num >> k) & 1; 
        cout << bit;
    }
    std::cout << "\n";
}

vector<int> generateGraycode(int n){

    vector<int> graycode = {0,1};

    if (n <= 1){
        if (n < 1) graycode.clear();
        return graycode;
    }

    for (int i = 0; i < n-1; i++){
        auto cur_size = graycode.size();
        for (int j = cur_size - 1; j >= 0; j--){
            graycode.push_back(graycode[j] | 1 << (i+1));
        }
    }

    return graycode;
}

int main (){

    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    vector<int> gray_code = {0, 1};
    gray_code = generateGraycode(n);
    for (auto i : gray_code) {
        printBinary(i,n);
    }

    return 0;
}