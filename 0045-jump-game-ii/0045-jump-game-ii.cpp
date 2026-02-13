class Solution {
public: 
    int dfs(int i, int dest, vector<int>& nums, vector<int>& dp){
        if(i>=dest)return 0;
        if(dp[i]!=-1)return dp[i];
        int steps = INT_MAX;
        // Try out jumping all the possible from the current index to the max jump
        for(int jump=1; jump<=nums[i]; jump++){
            steps = min(steps, 1+dfs(i+jump, dest, nums, dp));
        }
        if(steps==INT_MAX)return dp[i]=1e9;
        return dp[i]=steps;
    }
    int jump(vector<int>& nums) {
        if(nums[0]==0)return 0;
        int n = nums.size();
        if(n==1)return 0;
        vector<int> dp(n, -1);
        return dfs(0, n-1, nums, dp);
    }
};