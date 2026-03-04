class Solution {
public:
    int dfs(int i, vector<int>& days, vector<int>& costs, vector<int>& dp){
        if(i>=days.size())return 0;
        // Option 1
        if(dp[i]!=-1)return dp[i];
        int opt1 = costs[0]+dfs(i+1, days, costs, dp);
        // Option 2
        int k = i;
        while(k<days.size()&&days[k]<days[i]+7)k++;
        int opt2 = costs[1]+dfs(k, days, costs, dp);
        // Option 3
        k = i;
        while(k<days.size()&&days[k]<days[i]+30)k++;
        int opt3 = costs[2]+dfs(k, days, costs, dp);
        // Return the minimum you can make
        return min(opt1, min(opt2, opt3));
    }

    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n = days.size(); 
        vector<int> dp(n+1, 0);
        for(int i=n-1; i>=0; i--){
            int opt1 = costs[0]+dp[i+1];
            // Option 2
            int k = i;
            while(k<n&&days[k]<days[i]+7)k++;
            int opt2 = costs[1]+dp[k];
            // Option 3
            k = i;
            while(k<n&&days[k]<days[i]+30)k++;
            int opt3 = costs[2]+dp[k];
            // Return the minimum you can make
            dp[i]=min(opt1, min(opt2, opt3));
        }
        return dp[0];
        // return dfs(0, days, costs, dp);
    }
};