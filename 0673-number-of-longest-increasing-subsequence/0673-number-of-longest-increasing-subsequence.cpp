class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();
        int maxi =1;
        int way = 1;
        vector<int> ways(n, 1);
        vector<int> dp(n, 1);
        for(int i=0; i<n; i++){
            for(int prev=0; prev<i; prev++){
                if(nums[prev]<nums[i]&&dp[i]<dp[prev]+1){
                    dp[i]=dp[prev]+1;
                    ways[i]=ways[prev];
                }
                else if(nums[prev]<nums[i]&&dp[i]==dp[prev]+1){
                    ways[i]+=ways[prev];
                }
            }
            maxi = max(maxi, dp[i]);
        }
        int ans =0;
        for(int i =0; i<n; i++){
            if(dp[i]==maxi){
                ans+=ways[i];
            }
        }
        return ans;
    }
};