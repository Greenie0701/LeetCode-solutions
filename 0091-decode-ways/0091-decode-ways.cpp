class Solution {
public:

    int dfs(int i, string& s){
        if(i<=0)return 1;
        int one_pick = s[i]!='0'?dfs(i-1, s):0;
        int val = ((s[i-1]-'0')*10)+(s[i]-'0');
        int two_pick = val>=10&&val<=26?dfs(i-2, s):0;
        return two_pick+one_pick;
    }

    int numDecodings(string s) {
        // Base case when first index contains '0'
        if(s[0]=='0')return 0;
        int n = s.length();
        vector<int> dp(n, 0);
        if(n==1)return 1;
        dp[0] = 1;

        dp[1] = (s[1] != '0') ? dp[0] : 0;

        int val = ((s[0]-'0')*10)+(s[1]-'0');
        if(val >= 10 && val <= 26) 
            dp[1] += 1;
        for(int i=2; i<n; i++){
            int one_pick = s[i]!='0'?dp[i-1]:0;
            val = ((s[i-1]-'0')*10)+(s[i]-'0');
            int two_pick = val>=10&&val<=26?dp[i-2]:0;
            dp[i]=two_pick+one_pick;
        }
        return dp[n-1];
        // return dfs(n-1, s);
    }
};