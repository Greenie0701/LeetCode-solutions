class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> pq;
        for(int n:nums){
            pq.push(n);
        }
        int val=0;
        while(k){
            val = pq.top();
            pq.pop();
            k--;
        }
        return val;
    }
};