class Solution {
public:

    void dfs(string digits, vector<string>& combo, vector<string>& result, int index, string s){
        if(index==digits.size()){
            result.push_back(s);
            return;
        }
        int digit = digits[index]-'0';
        for(int i=0; i<combo[digit].size(); i++){
            dfs(digits, combo, result, index+1, s+combo[digit][i]);
        }
    }

    vector<string> letterCombinations(string digits) {
        vector<string> s={"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        vector<string> result;
        dfs(digits, s, result, 0, "");
        return result;
    }
};