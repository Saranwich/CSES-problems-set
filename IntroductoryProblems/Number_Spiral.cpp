#include <bits/stdc++.h>

using namespace std;

void num_spiral() {
    long long x, y;
    cin >> y >> x;
    unsigned long long result;
    if (y == x) result = x * x - x + 1;
    else if (y > x) {
        if (y % 2 == 0) result = y*y - x + 1;
        else result = (y - 1) * (y - 1) + x;
    }else{
        if (x % 2) result = x*x - y + 1;
        else result = (x - 1) * (x - 1) + y;
    }
    cout << result << endl;
}

int main (){

    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    for (int i = 0; i < n; i++){
        num_spiral();
    }


    return 0;
}