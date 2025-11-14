class Solution {
public:
    bool palindrome(int start, int end, string s){
        while(start<end){
            if(s[start]!=s[end]){
                return false;
            }
            start++;
            end--;
        }
        return true;
    }
    void find(vector<string>& ds, vector<vector<string>>& result, string s, int index){
        if(index==s.length()){
            result.push_back(ds);
            return;
        }
        for(int i=index; i<s.length(); i++){
            if(palindrome(index, i, s)){
                ds.push_back(s.substr(index, i-index+1));
                find(ds, result, s, i+1);
                ds.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<string> ds;
        vector<vector<string>> result;
        find(ds, result, s, 0);
        return result;
    }
};