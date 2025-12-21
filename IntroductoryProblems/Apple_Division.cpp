#include <bits/stdc++.h>
using namespace std;

long long get_min_diff (vector<int>& apples, size_t start_index = 0, long long s1 = 0, long long s2 = 0){
    if (start_index >= apples.size()-1){
        return min(abs(s1 + apples[apples.size()-1]-s2), abs(s1 - apples[apples.size()-1]-s2));
    }

    long long dif1 = get_min_diff(apples,start_index+1,s1 + apples[start_index], s2);
    long long dif2 = get_min_diff(apples,start_index+1,s1, apples[start_index] + s2);
    
    return min(dif1,dif2);
}

int main (){

    ios::sync_with_stdio(0);
    cin.tie(0);
    size_t n;
    cin >> n;

    vector<int> apples; apples.reserve(n);
    int buffer;
    for (size_t i = 0; i < n; i++){
        cin >> buffer;
        apples.push_back(buffer);
    }

    long long diff = get_min_diff(apples);
    cout << diff;

    return 0;
}