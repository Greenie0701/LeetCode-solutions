class Solution {
public:
    bool dfs(int i, vector<int>& nums, int n, vector<int>& dp){
        if(i==n)return dp[i]=true;
        if(dp[i]!=-1)return dp[i];
        if(i+1<n&&nums[i]==nums[i+1]){
            if(dfs(i+2, nums, n, dp))return dp[i]=true;
        }
        if(i+2<n){
            if(nums[i]+1==nums[i+1]&&nums[i]+2==nums[i+2]){
                if(dfs(i+3, nums, n, dp))return dp[i]=true;
            }
            if(nums[i]==nums[i+1]&&nums[i]==nums[i+2]){
                if(dfs(i+3, nums, n, dp))return dp[i]=true;
            }
        }
        return dp[i]=false;

    }

    bool validPartition(vector<int>& nums) {
        
        int n = nums.size();
        vector<int> dp(n+1, -1);
        return dfs(0, nums, n, dp);
    }
};