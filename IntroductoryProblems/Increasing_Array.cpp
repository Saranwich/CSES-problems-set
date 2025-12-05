#include <bits/stdc++.h>

using namespace std;

int main (){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    long long int moves = 0;
    vector<int> nums(n);
    for (int i = 0; i < n; i++){
        cin >> nums[i];
        if (i == 0) continue;
        if (nums[i] < nums[i-1]){
            moves += nums[i-1] - nums[i];
            nums[i] = nums[i-1];
        }
    }
    cout << moves << endl;
    return 0;
}