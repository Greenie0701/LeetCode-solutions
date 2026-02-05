class Solution {
public:
    int dfs(int i, int j, string& s){
        if(i>j)return 0;
        if(i==j)return 1;

        if(s[i]==s[j]){
            return 2+dfs(i+1, j-1, s);
        }
        else{
            return max(dfs(i+1, j, s), dfs(i, j-1, s));
        }
    }
    int longestPalindromeSubseq(string s) {
        return dfs(0, s.length()-1, s);
    }
};