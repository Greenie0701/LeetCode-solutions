class Solution {
public:
    bool palin(string s, int start, int end){
        while(start<end){
            if(s[start]!=s[end]){
                return false;
            }
            start++;
            end--;
        }
        return true;
    }
    void generate( vector<vector<string>>& result, vector<string>& ds, int index, string s){
        if(index==s.length()){
            result.push_back(ds);
            return;
        }
        for(int i=index; i<s.length(); i++){
            if(palin(s, index, i)){
                ds.push_back(s.substr(index, i-index+1));
                generate(result, ds, i+1, s);
                ds.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<string> ds;
        vector<vector<string>> result;
        generate(result, ds, 0, s);
        return result;
    }
};