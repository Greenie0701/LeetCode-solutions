class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int sum =0;
        int left =0;
        int len = INT_MAX;
        for(int right=0; right<nums.size(); right++){
            // Add current element to the sum
            sum+=nums[right];
            // Check if the sum is greater than or equal to target and keep on shrinking
            while(sum>=target){
                len = min(len, right-left+1);
                sum-=nums[left];
                left++;
            }
        }
        if(len==INT_MAX)return 0;
        return len;
    }
};