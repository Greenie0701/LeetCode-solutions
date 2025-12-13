class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string s="";
        for(int i=0; i<strs[0].length(); i++){
            for(string str:strs){
                if(i==str.length()||strs[0][i]!=str[i]){
                    return s;
                }
            }
            s+=strs[0][i];
        }
        return s;
    }
};