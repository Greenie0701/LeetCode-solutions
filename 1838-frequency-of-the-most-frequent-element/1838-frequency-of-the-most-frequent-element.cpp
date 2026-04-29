class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int left = 0;
        int right = 0;
        long long total_sum=0;
        int maxi = 1;
        for(int right=0; right<nums.size(); right++){
            int target = nums[right];
            total_sum+=nums[right];
            // Check if it is not valid window
            while(right<nums.size()&&(long long)(right-left+1)*(target)>total_sum+k){
                total_sum-=nums[left];
                left++;
            }
            maxi = max(maxi, right-left+1);
        }
        return maxi;
    }
};