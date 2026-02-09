class Solution {
public:
    // int dfs(string& s, string& t, int i, int j){
    //     if(i<0)return j+1;
    //     if(j<0)return i+1;
    //     if(s[i]==t[j]){
    //         return dfs(s, t, i-1, j-1);
    //     }
    //     int insert = dfs(s, t, i,j-1);
    //     int deletion = dfs(s, t, i-1, j);
    //     int replace = dfs(s, t, i-1, j-1);

    //     return 1+min(insert, min(deletion, replace));
    // }
    int minDistance(string word1, string word2) {
        int l1 = word1.length();
        int l2 = word2.length();
        // return dfs(word1, word2, l1-1, l2-1);
        vector<vector<int>> dp(l1+1, vector<int>(l2+1, 0));
        for(int i=0; i<=l1; i++){
            dp[i][0]=i;
        }
        for(int i=0; i<=l2; i++){
            dp[0][i]=i;
        }
        for(int i=1; i<=l1; i++){
            for(int j=1; j<=l2; j++){
                if(word1[i-1]==word2[j-1]){
                    dp[i][j]=dp[i-1][j-1];
                }
                else{
                    dp[i][j]=1+min(dp[i][j-1], min(dp[i-1][j-1], dp[i-1][j]));
                }
            }
        }
        return dp[l1][l2];
    }
};

//    "" r o s
// "" 0  1 2 3
// h  1  1 2 3
// o  2  2 1 2
// r  3  2 2 2
// s  4  3 3 2
// e  5  4 4 3


