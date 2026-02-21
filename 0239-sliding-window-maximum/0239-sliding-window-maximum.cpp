class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> q;
        vector<int> result;
        for(int i=0; i<nums.size(); i++){
            // Check if the value in the front is within current window
            if(q.front()==i-k)q.pop_front();
            // Check if the element in the back is smaller than current element, if yes remove
            while(!q.empty()&&nums[q.back()]<=nums[i])q.pop_back();
            // Now push the element into the deque
            q.push_back(i);
            // Check if we are at the end of window
            if(i>=k-1)result.push_back(nums[q.front()]);
        }
        return result;
    }
};