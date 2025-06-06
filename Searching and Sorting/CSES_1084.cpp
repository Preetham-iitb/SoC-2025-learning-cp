#include <bits/stdc++.h>
using namespace std;

// CSES Problem: Apartments

int main(){
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> a(n), b(m);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    for(int i = 0; i < m; i++){
        cin >> b[i];
    }
    int ans = 0;
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    for(int i = 0, j = 0; i < n && j < m;){
        if(abs(a[i] - b[j]) <= k){
            ans++;
            i++;
            j++;
        } 
        else if(a[i] < b[j]) i++;
        else j++;
    }
    cout << ans << '\n';
}