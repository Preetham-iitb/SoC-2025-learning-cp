#include <bits/stdc++.h>
using namespace std;

// Maximum Number of Vowels in a Substring of Given Length

// int main(){
//     string s;
//     int k, maxCount = 0, count = 0;
//     cin >> s >> k;
//     for(int i = 0; i < k; i++) {
//         if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u') {
//             count++;
//         }
//     }
//     maxCount = count;
//     for(int i = k; i < s.size(); i++) {
//         if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u') {
//             count++;
//         }
//         if(s[i - k] == 'a' || s[i - k] == 'e' || s[i - k] == 'i' || s[i - k] == 'o' || s[i - k] == 'u') {
//             count--;
//         }
//         maxCount = max(maxCount, count);
//     }
//     cout << maxCount << '\n';
// }

class Solution {
public:
    int maxVowels(string s, int k) {
        int maxCount = 0, count = 0;
        for(int i = 0; i < k; i++) {
            if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u') count++;
        }
        maxCount = count;
        for(int i = k; i < s.size(); i++) {
            if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u') count++;
            if(s[i - k] == 'a' || s[i - k] == 'e' || s[i - k] == 'i' || s[i - k] == 'o' || s[i - k] == 'u') count--;
            maxCount = max(maxCount, count);
        }
        return maxCount;
    }
};

int main(){
    Solution sol;
    string s;
    int k;
    cin >> s >> k;
    cout << sol.maxVowels(s, k) << '\n';
    return 0;
}