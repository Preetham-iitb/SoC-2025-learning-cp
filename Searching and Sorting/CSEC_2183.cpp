#include <bits/stdc++.h>
using namespace std;

// Missing Coin Sum

int main(){
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    sort(arr.begin(), arr.end());
    if(arr[0] != 1){
        cout << 1 << '\n';
        return 0;
    }
    long long sum = 1;
    for (int i = 1; i < n; i++){
        if (sum + 1 < arr[i]){
            break;
        }
        sum += arr[i];
    }
    cout << sum + 1  << '\n';
}