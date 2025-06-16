#include <bits/stdc++.h>
using namespace std;

class KthLargest {
private:
    int k;
    priority_queue<int, vector<int>, greater<int>> pq;
public:
    KthLargest(int k, vector<int>& nums) {
        this->k = k;
        auto endPointer = nums.begin() + min(k, (int)nums.size());
        pq = priority_queue<int, vector<int>, greater<int>> (nums.begin(), endPointer);
        for(int i = k; i < nums.size(); ++i) {
            pq.push(nums[i]);
            pq.pop();
        }
    }
    
    int add(int val) {
        pq.push(val);
        if(pq.size() > k) pq.pop();
        return pq.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */

int main() {
    vector<int> nums = {4, 5, 8, 2};
    int k = 3;
    KthLargest* obj = new KthLargest(k, nums);
    cout << obj->add(3) << endl; // returns 4
    cout << obj->add(5) << endl; // returns 5
    cout << obj->add(10) << endl; // returns 5
    cout << obj->add(9) << endl; // returns 8
    cout << obj->add(4) << endl; // returns 8
    delete obj;
    return 0;