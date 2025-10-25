class Solution {
public:
    void genseq(vector<string>& ans, int open, int close, string s, int n){
        if(s.length()==2*n){
            ans.push_back(s);
            return;
        }
        if(open<n)genseq(ans, open+1, close, s+"(", n);
        if(close<open)genseq(ans, open, close+1, s+")", n);
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        genseq(ans, 0, 0,"", n);
        return ans;
    }
};