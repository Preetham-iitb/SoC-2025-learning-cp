#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int firstUniqChar(string s) {
        int count[26]={0};
        for(int i=0;i<s.length();i++){
            count[s[i]-'a']++;
        }
        for(int i=0;i<s.length();i++){
            if(count[s[i]-'a']==1){
                return i;
            }
        }
        return -1;
    }
};

int main() {
    Solution solution;
    string s;
    cin >> s;
    int result = solution.firstUniqChar(s);
    cout << result << endl;
    return 0;
}