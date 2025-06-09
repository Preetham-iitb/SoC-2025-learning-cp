#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isSubsequence(string s, string t) {
        int i = 0, j = 0;
        for(; i < s.size() && j < t.size(); ) {
            if (s[i] == t[j]) {
                i++;
            }
            j++;
        }
        if(i < s.size()) return false;
        return true;
    }
};

int main(){
    Solution sol;
    string s, t;
    cin >> s >> t;
    cout << sol.isSubsequence(s, t) << '\n';
    return 0;
}