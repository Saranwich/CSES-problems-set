#include <bits/stdc++.h>

using namespace std;

void coin (){
    int a,b;
    cin >> a >> b;

    if ((a+b) % 3 == 0 && min(a,b) >= max(a,b) / 2){
        cout << "YES" << endl;
    }else{
        cout << "NO" << endl;
    }


}

int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    for (auto i = 0; i < t; i++ ){
        coin();
    }


    return 0;
}