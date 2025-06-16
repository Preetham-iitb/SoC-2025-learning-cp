#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
    vector<vector<int>> res;
    priority_queue<pair<int,pair<int,int>>> pq;
    for(auto x:nums1){
        for(auto y:nums2){
            int sum=x+y;
            if( pq.size()<k){
                 pq.push({sum,{x,y}});
            }
            else if(sum < pq.top().first){
                pq.pop();
                pq.push({sum,{x,y}});
            }
            else break;
        }
    }
    while(pq.size()>0){
       auto p=pq.top().second;
        pq.pop();
        res.push_back({p.first,p.second});
    }
    return res;
}
};

int main() {
    Solution solution;
    vector<int> nums1 = {1, 7, 11};
    vector<int> nums2 = {2, 4, 6};
    int k = 3;
    vector<vector<int>> result = solution.kSmallestPairs(nums1, nums2, k);
    
    for (const auto& pair : result) {
        cout << "[" << pair[0] << ", " << pair[1] << "] ";
    }
    cout << endl;
    
    return 0;
}