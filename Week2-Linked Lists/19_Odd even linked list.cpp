#include <bits/stdc++.h>
using namespace std;

// Odd Even Linked List

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if (head == nullptr || head->next == nullptr) return head;
        ListNode* oddTmp = head;
        ListNode* evenTmp = head->next;
        ListNode* evenHead = head->next;
        while(evenTmp != nullptr && evenTmp->next != nullptr){
            oddTmp->next = evenTmp->next;
            oddTmp = oddTmp->next;
            evenTmp->next = evenTmp->next->next;
            evenTmp = evenTmp->next;
        }
        oddTmp->next = evenHead;
        return head;
    }
};

int main() {
    // Example usage
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    Solution sol;
    ListNode* result = sol.oddEvenList(head);

    // Print the modified list
    while (result != nullptr) {
        cout << result->val << " ";
        result = result->next;
    }
    cout << endl; // Output: 1 3 5 2 4

    // Clean up memory
    while (head != nullptr) {
        ListNode* temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}