class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        priority_queue<int, vector<int>, greater<int>> pq;
        for(int i:nums){
            pq.push(i);
        }
        int i=0;
        while(!pq.empty()){
            nums[i] = pq.top();
            i++;
            pq.pop();
        }
        return nums;
    }
};