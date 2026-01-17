class Solution {
public:
    void dfs(int len, vector<string>& result, string s, int open, int close){
        // Basecase - When the length of s is 2*n
        if(s.length()==2*len){
            result.push_back(s);
            return;
        }

        // Check if can add open paranthesis
        if(open<len)dfs(len, result, s+"(", open+1, close);
        if(close<open)dfs(len, result, s+")", open, close+1);
    }
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        dfs(n, result, "", 0, 0);
        return result;
    }
};