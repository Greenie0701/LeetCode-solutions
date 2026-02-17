class Solution {
public:
    bool static comp(string& s1, string& s2){
        return s1.length()<s2.length();
    }
    bool IsPredecessor(string& s1, string& s2){
        // Check if it is possible chain by comparing their length
        if(s1.length()+1!=s2.length())return false;
        int i = 0;
        int j = 0;
        bool skipped = false;
        while(i<s1.length()){
            if(s1[i]==s2[j]){
                i++;
                j++;
            }
            else{
                if(skipped)return false;
                j++;
                skipped = true;
            }
        }
        return true;
    }
    int longestStrChain(vector<string>& words) {
        int n = words.size();
        if(n==1)return 1;
        sort(words.begin(), words.end(), comp);
        int maxi = 1;
        vector<int> dp(n, 1);
        for(int i=0; i<n; i++){
            for(int prev=0; prev<i; prev++){
                if(IsPredecessor(words[prev], words[i])&&dp[i]<dp[prev]+1){
                    dp[i]=dp[prev]+1;
                }
            }
            maxi = max(maxi, dp[i]);
        }
        return maxi;
    }
};

