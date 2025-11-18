class Solution {
public:
    int count(vector<int>& nums, int goal){
        if(goal<0){
            return 0;
        }
        int l = 0;
        int r = 0;
        int count = 0;
        int end = nums.size();
        int sum = 0;
        while(r<end){
            sum+=nums[r];
            while(sum>goal){
                sum-=nums[l];
                l++;
            }
            count+=(r-l+1);
            r++;
        }
        return count;
    }
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return(count(nums, goal)-count(nums, goal-1));
    }
};