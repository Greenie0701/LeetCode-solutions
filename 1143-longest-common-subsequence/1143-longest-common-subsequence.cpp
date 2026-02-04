class Solution {
public:
    int lcs(int i, string& text1, int j, string& text2, vector<vector<int>>& dp){
        if(i<0||j<0)return 0;
        if(dp[i][j]!=-1)return dp[i][j];
        if(text1[i]==text2[j]){
            return dp[i][j]=1+lcs(i-1, text1, j-1, text2, dp);
        }
        else{
            return dp[i][j]=max(lcs(i-1, text1, j, text2, dp), lcs(i, text1, j-1, text2, dp));
        }
    }
    int longestCommonSubsequence(string text1, string text2) {
        int i = text1.length();
        int j = text2.length();
        vector<vector<int>> dp(i, vector<int>(j, -1));
        return lcs(i-1, text1, j-1, text2, dp);
    }
};