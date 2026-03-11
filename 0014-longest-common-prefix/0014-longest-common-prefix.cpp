class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string result = "";
        for(int i=0; i<strs[0].length(); i++){
            for(string& s:strs){
                if(s.length()<=strs[0].length()&&s[i]==strs[0][i])continue;
                else return result;
            }
            result+=strs[0][i];
        }
        return result;
    }
};