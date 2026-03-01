class Solution {
public:

    bool isPalin(int i, int j, string& s){
        while(i<j){
            if(s[i]!=s[j])return false;
            i++;
            j--;
        }
        
        return true;
    }

    // int dfs(int i, int n, string& s){
    //     if(i==n)return 0;
    //     int cuts = INT_MAX;
    //     // Lets try to parition at every possible k and return the minimal cut
    //     for(int k=i; k<n; k++){
    //         if(isPalin(i, k, s)){
    //             cuts = min(cuts, 1+dfs(k+1, n, s));
    //         }
    //     }
    //     return cuts;
    // }

    int minCut(string s) {
        int n = s.length();
        if(n<=1)return 0;
        string rev = s;
        reverse(rev.begin(), rev.end());
        if(rev==s)return 0;
        // return dfs(0, n, s)-1;
        vector<int> dp(n+1, 0);
        for(int i=n-1; i>=0; i--){
            int cuts = INT_MAX;
            // Lets try to parition at every possible k and return the minimal cut
            for(int k=i; k<n; k++){
                if(isPalin(i, k, s)){
                    cuts = min(cuts, 1+dp[k+1]);
                }
            }
            dp[i]=cuts;
        }
        return dp[0]-1;
    }
};