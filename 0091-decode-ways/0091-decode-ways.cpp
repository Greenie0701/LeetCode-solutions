class Solution {
public:
    int numDecodings(string s) {
        if (s[0] == '0') return 0;

        int n = s.length();
        if (n < 2) return 1;

        vector<int> dp(n, 0);
        dp[0] = 1;

        int val = (s[0]-'0')*10 + (s[1]-'0');

        dp[1] = 0;

        // single digit contribution
        if (s[1] != '0')
            dp[1] += dp[0];

        // two digit contribution
        if (val >= 10 && val <= 26)
            dp[1] += 1;

        for (int i = 2; i < n; i++) {

            int one = (s[i] == '0') ? 0 : dp[i-1];

            val = (s[i-1]-'0')*10 + (s[i]-'0');
            int two = (val >= 10 && val <= 26) ? dp[i-2] : 0;

            dp[i] = one + two;
        }

        return dp[n-1];
    }
};