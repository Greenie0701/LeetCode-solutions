class Solution {
public:
    bool dfs(int i, int target, vector<int>& nums,vector<vector<int>>& dp){
        if(target==0)return true;
        if(i==0){
            return dp[0][target]=(nums[0]==target);
        }
        if(i<0)return false;
        if(dp[i][target]!=-1)return dp[i][target];
        bool not_pick = dfs(i-1, target, nums, dp);
        bool pick = false;
        if(nums[i]<=target){
            pick = dfs(i-1, target-nums[i], nums, dp);
        }
        return dp[i][target]=(pick||not_pick);
    }


    bool canPartition(vector<int>& nums) {
        int totalsum = accumulate(nums.begin(), nums.end(), 0);
        if((totalsum&1)==1)return false;
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>((totalsum/2)+1, -1));
        return dfs(n-1, totalsum/2, nums, dp);
    }
};


 



