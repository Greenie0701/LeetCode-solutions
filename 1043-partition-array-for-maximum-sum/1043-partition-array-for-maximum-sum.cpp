class Solution {
public:

    int dfs(int i, int k, int n, vector<int>& arr, vector<int>& dp){
        // Base case when you reach end of the array
        if(i==n)return 0;
        if(dp[i]!=-1)return dp[i];
        int sum = 0;
        int maxi = INT_MIN;
        // Try partitioning from the front till k 
        int length = 0;
        for(int j=i; j<min(n, i+k); j++){
            length++;
            maxi = max(maxi, arr[j]);
            int remain = dfs(j+1, k, n, arr, dp);
            sum = max(sum, maxi*length+remain);
        }
        return dp[i]=sum;
    }

    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int> dp(n , -1);
        return dfs(0, k, n, arr, dp);
    }
};