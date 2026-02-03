class Solution {
public:
    int countPartitions(int n, int diff, vector<int>& arr) {
        int t = accumulate(arr.begin(), arr.end(),0);
        if((t+diff)&1)return 0;
        int target = (t+diff)/2;
        vector<vector<int>> dp(n, vector<int>(target+1, 0));   
        if (arr[0] == 0)
            dp[0][0] = 2;    
        else
            dp[0][0] = 1;
        if(arr[0]!=0&&arr[0]<=target)dp[0][arr[0]]=1;
        for(int i=1; i<n; i++){
            for(int t=0; t<=target; t++){
                int not_pick = dp[i-1][t];
                int pick = 0;
                if(arr[i]<=t){
                    pick = dp[i-1][t-arr[i]];
                }
                dp[i][t] = (pick+not_pick);
            }
        }
        return dp[n-1][target];
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int total = accumulate(nums.begin(), nums.end(), 0);
        if (total < abs(target)) return 0;
        if ((total + target) & 1) return 0;
        return countPartitions(nums.size(), target, nums);
    }
};