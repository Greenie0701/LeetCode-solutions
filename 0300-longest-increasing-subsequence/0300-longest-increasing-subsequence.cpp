class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n, 1);
        int maxi =1;
        for(int i=1; i<n; i++){
            for(int prev=0; prev<i; prev++){
                if(nums[prev]<nums[i]&&dp[prev]+1>dp[i]){
                    dp[i]=dp[prev]+1;
                }
            }
            if(maxi<dp[i]){
                maxi=dp[i];
            }
        }
        return maxi;
    }
};