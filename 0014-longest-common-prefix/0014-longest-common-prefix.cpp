class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans="";
        // The first loop is going to iterate untill length of first array
        for(int i=0; i<strs[0].length(); i++){
            // Iterate every string in string vector
            for(string str : strs){
                // Check if it is out of bounds or the char in the string are not eq
                // If this is the case return ans
                if(i==str.length() || str[i]!=strs[0][i]){
                    return ans;
                }
            }
            // If not, the chars in the string is equal 
            ans+=strs[0][i];
        }
        return ans;
    }
};