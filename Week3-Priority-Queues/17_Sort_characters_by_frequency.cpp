#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int> mp;
        priority_queue<pair<int,int>> maxH;
        string ans;
        for (char ch : s){
            mp[ch]++;
        }
        for (auto [ch,cnt] : mp){
            maxH.push({cnt,ch});
        }
        while (!maxH.empty()){
            auto& [x,y] = maxH.top();
            ans.append(x,y);
            maxH.pop();
        }
        return ans;
    }
};

int main() {
    Solution solution;
    string s;
    cin >> s;
    string result = solution.frequencySort(s);
    cout << result << endl; // Output: sorted string by frequency
    return 0;
}