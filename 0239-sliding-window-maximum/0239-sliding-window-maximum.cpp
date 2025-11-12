class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> d;
        vector<int> v;
        for(int i=0;i<nums.size();i++){
            if(!d.empty()&&d.front()==i-k)d.pop_front();

            while(!d.empty()&&nums[d.back()]<=nums[i]){
                d.pop_back();
            }
            d.push_back(i);
            if(i>=k-1){
                v.push_back(nums[d.front()]);
            }
        }
        return v;
    }
};