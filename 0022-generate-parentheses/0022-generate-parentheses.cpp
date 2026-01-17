class Solution {
public:
    void gen(int open, int close, string s, int n, vector<string>& result){
        if(s.length()==2*n){
            result.push_back(s);
            return;
        }
        if(open<n)gen(open+1, close, s+'(', n, result);
        if(close<open)gen(open, close+1, s+')', n, result);
    }
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        gen(0, 0, "", n, result);
        return result;
    }
};