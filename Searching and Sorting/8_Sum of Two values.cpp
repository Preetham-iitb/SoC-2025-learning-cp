#include <bits/stdc++.h>
using namespace std;

// Sum of Two Values

int main(){
    int n, sum;
    cin >> n >> sum;
    vector<pair<int, int>> indices(n);
    for (int i = 0; i < n; i++) {
        cin >> indices[i].first;
        indices[i].second = i + 1;
    }
    for (int i = 0; i < n; i++) ;
    sort(indices.begin(), indices.end());
    int left = 0, right = n - 1;
    for (;left < right;){
        if (indices[left].first + indices[right].first == sum) {
            cout << indices[left].second << " " << indices[right].second << '\n';
            return 0;
        }
        else if (indices[left].first + indices[right].first < sum) left++;
        else right--;
    }
    if (left >= right) {
        cout << "IMPOSSIBLE\n";
    }
}