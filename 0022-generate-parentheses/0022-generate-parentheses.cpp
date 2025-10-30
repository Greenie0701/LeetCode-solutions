class Solution {
public:
    void ParenthesesCombination(vector<string>& result, int open, int close, int size, string valid){
        if(valid.length()==size*2){
            result.push_back(valid);
            return;
        }
        if(open<size)ParenthesesCombination(result, open+1, close, size, valid+"(");
        if(close<open)ParenthesesCombination(result, open, close+1, size, valid+")");
    }
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        ParenthesesCombination(result, 0, 0, n, "");
        return result;
    }
};