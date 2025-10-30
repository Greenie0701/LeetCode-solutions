class Solution {
public:
    void find(vector<string>& result, int n, int open, int close, string valid){
        if(valid.length()==2*n){
            result.push_back(valid);
            return;
        }
        if(open<n)find(result, n, open+1, close, valid+"(");
        if(close<open)find(result, n, open, close+1, valid+")")
    }
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        find(result, n, 0, 0, "");
        return result;
    }
};