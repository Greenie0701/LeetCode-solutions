class Solution {
public:
    bool ispalin(int i, int j, string& s){
        while(i<j){
            if(s[i]!=s[j])return false;
            i++;
            j--;
        }
        return true;
    }
    // int dfs(int i, int n, string& s, vector<int>& dp){
    //     if(i==n)return 0;
    //     if(dp[i]!=-1)return dp[i];
    //     int cuts = 1e9;
    //     // Try paritioning the string at k and check if the cut makes a palindrome cut
    //     for(int k=i; k<n; k++){
    //         if(ispalin(i, k , s)){
    //             cuts = min(cuts, 1+dfs(k+1, n, s,dp));
    //         }
    //     }
    //     return dp[i]=cuts;
    // }

    int minCut(string s) {
        int n = s.length();
        if(n<=1)return 0;
        string rev = s;
        vector<int> dp(n+1, 0);
        dp[n]=0;
        reverse(rev.begin(), rev.end());
        if(rev==s)return 0;
        // return dfs(0, n, s, dp)-1;
        for(int i=n-1; i>=0; i--){
            int cuts = 1e9;
            // Try paritioning the string at k and check if the cut makes a palindrome cut
            for(int k=i; k<n; k++){
                if(ispalin(i, k , s)){
                    cuts = min(cuts, 1+dp[k+1]);
                }
            }
            dp[i]=cuts;
        }
        return dp[0]-1;
    }
};