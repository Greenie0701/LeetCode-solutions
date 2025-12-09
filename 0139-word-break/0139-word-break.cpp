class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<bool> dp(s.length()+1, false);
        dp[s.length()]=true;
        for(int i=s.length()-1; i>=0; i--){
            for(auto w:wordDict){
                if(i+w.length()<=s.length() && w==s.substr(i, w.length())){
                    dp[i]=dp[i+w.length()];
                }
                if(dp[i]){
                    break;
                }
            }
        }
        return dp[0];
    }
};