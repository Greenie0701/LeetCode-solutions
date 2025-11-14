class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int size=s.length();
        vector<bool> dp(size+1, false);
        dp[size]=true;
        for(int i=size-1; i>=0; i--){
            for(string word:wordDict){
                if(word.size()+i<=s.length() && word==s.substr(i, word.length())){
                    dp[i] = dp[i+word.length()];
                }
                if(dp[i]){
                    break;
                }
            }
        }
        return dp[0];
    }
};