class Solution {
public:
    bool palin(string s,int start, int end){
        while(start<end){
            if(s[start]!=s[end]){
                return false;
            }
            start++;
            end--;
        }
        return true;
    }
    void palindrome_partition(int index, string s, vector<string>& ds, vector<vector<string>>& result){
        if(index==s.length()){
            result.push_back(ds);
            return;
        }
        for(int i=index; i<s.length(); ++i){
            if(palin(s, index, i)){
                ds.push_back(s.substr(index, i-index+1));
                palindrome_partition(i+1, s, ds, result);
                ds.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> result;
        vector<string> ds;
        palindrome_partition(0, s, ds, result);
        return result;
    }
};