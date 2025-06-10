#include <bits/stdc++.h>
using namespace std;

// CSES Problem: Maximum Subarray Sum
int main(){
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    long long sum = arr[0];
    long long current_sum = arr[0];
    for(int a = 1; a < n; a++){
        current_sum = max((long long)arr[a], current_sum + arr[a]);
        sum = max(sum, current_sum);
    }
    cout << sum << '\n';
    return 0;
}
