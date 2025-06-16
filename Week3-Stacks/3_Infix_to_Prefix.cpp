#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
int priority(char op) {
        if(op == '+' || op == '-') return 1;
        if(op == '*' || op == '/') return 2;
        if(op == '^') return 3;
        return 0;
    }
    string infixToPostfix(string& s) {
        // code here
        int i=0;
        stack<char>st;
        int n=s.length();
        string ans="";
        while(i<n){
            if((s[i]>='A' && s[i]<='Z') || (s[i]>='a' && s[i]<='z') || (s[i]>='0' && s[i]<='9')){
                ans+=s[i];
            }
            else if(s[i]=='(') st.push(s[i]);
            else if(s[i]==')'){
                while(!st.empty() && st.top()!='('){
                    ans+=st.top();
                    st.pop();
                }
                st.pop();
            }
            else{
                while(!st.empty()&& (priority(s[i])<=priority(st.top()))){
                    ans+=st.top();
                    st.pop();
                }
                st.push(s[i]);
            }
            i++;
        }
        while(!st.empty()){
            ans+=st.top();
            st.pop();
        }
        return ans;
    }
};
int main() {
    Solution solution;
    string s;
    cin >> s;
    string result = solution.infixToPostfix(s);
    cout << result << endl;
    return 0;
}