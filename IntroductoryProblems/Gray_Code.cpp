#include <bits/stdc++.h>

using namespace std;

void printBinary(int num, int n) {
    for (int k = n - 1; k >= 0; k--) {
        int bit = (num >> k) & 1; 
        cout << bit;
    }
    std::cout << "\n";
}

vector<int> generateGraycodeFromPrevious(int n, vector<int>& graycode){

    if (n < 1){
        return graycode;
    }

    vector<int> prev_graycode = graycode;

    for (auto time = 0; time < n; time++){
        bool switcher = 0;
        graycode.clear();
        for (auto i : prev_graycode){
            if (switcher) {
                graycode.push_back(( i << 1 ) + 1 );
                graycode.push_back( i << 1 );
            }else{
                graycode.push_back( i << 1 );
                graycode.push_back(( i << 1 ) + 1 );
            }
            switcher = ( switcher + 1 ) % 2;
        }
        prev_graycode = graycode;
    }
    

    return graycode;
}

int main (){

    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    vector<int> gray_code = {0, 1};
    gray_code = generateGraycodeFromPrevious(n-1, gray_code);
    for (auto i : gray_code) {
        printBinary(i,n);
    }

    return 0;
}