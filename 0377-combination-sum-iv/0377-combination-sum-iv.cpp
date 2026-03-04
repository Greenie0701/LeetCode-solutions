class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        // if(target==0)return 1;
        // if(target<1)return 0;
        // int ans = 0;
        // for(int num:nums){
        //     ans+=combinationSum4(nums, target-num);
        // }
        // return ans;
        vector<unsigned int> dp(target+1, 0);
        dp[0]=1;
        int ans = 0;
        for(int i=1; i<=target; i++){
            for(int num:nums){
                if(num<=i){
                    dp[i]+=dp[i-num];
                }
            }
        }
        return dp[target];
    }
};