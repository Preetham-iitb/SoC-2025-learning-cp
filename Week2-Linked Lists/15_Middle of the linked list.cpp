#include <bits/stdc++.h>
using namespace std;

// Middle of the Linked List

/**
 * Definition for singly-linked list.*/
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        int length = 0;
        ListNode* ans = head;
        ListNode* ptr = head;
        while (ptr != nullptr && ptr->next != nullptr){
            ans = ans->next;
            ptr = ptr->next->next;
        }
        return ans;
    }
};

int main(){
    // Example usage
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    Solution sol;
    ListNode* middle = sol.middleNode(head);
    
    cout << "Middle Node Value: " << middle->val << endl; // Output: 3

    // Clean up memory
    while (head != nullptr) {
        ListNode* temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}