class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> result;
        deque<int> d;
        for(int i=0; i<nums.size(); i++){
            // Checks the maximum guy is part of current window
            if(d.front()==i-k)d.pop_front();
            // Maintain the dequeue in decreasing order
            while(!d.empty()&&nums[d.back()]<=nums[i])d.pop_back();
            // Push the current element in the dequeue
            d.push_back(i);
            // Extract maximum of every k size window
            if(i>=k-1)result.push_back(nums[d.front()]);
        }
        return result;
    }
};