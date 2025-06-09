#include <bits/stdc++.h>
using namespace std;

// Palindrome Linked List

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    bool isPalindrome(ListNode* head) {
        vector<int> values;
        while (head != nullptr){
            values.push_back(head->val);
            head = head->next;
        }
        int left = 0, right = values.size()-1;
        while (left < right){
            if (values[left] != values[right]) return false;
            left++;
            right--;
        }
        return true;
    }
};

int main() {
    // Example usage
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(2);
    head->next->next->next = new ListNode(1);

    Solution sol;
    bool result = sol.isPalindrome(head);
    
    cout << "Is Palindrome: " << (result ? "Yes" : "No") << endl; // Output: Yes

    // Clean up memory
    while (head != nullptr) {
        ListNode* temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}