#include <bits/stdc++.h>
using namespace std;

class MyStack {
public:
    queue<int> kyu;
    MyStack() {}
    void push(int x) {
        kyu.push(x);
        int n = kyu.size();
        while (--n) {
            kyu.push(kyu.front());
            kyu.pop();
        }
    }
    int pop() {
        int val = kyu.front();
        kyu.pop();
        return val;
    }
    int top() {
        return kyu.front();
    }
    bool empty() {
        return kyu.empty();
    }
};

int main() {
    MyStack stack;
    stack.push(1);
    stack.push(2);
    cout << stack.top() << endl; // returns 2
    cout << stack.pop() << endl; // returns 2
    cout << stack.empty() << endl; // returns false
    return 0;
}