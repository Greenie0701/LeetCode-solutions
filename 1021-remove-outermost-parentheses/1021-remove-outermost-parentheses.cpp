class Solution {
public:
    string removeOuterParentheses(string s) {
        int level = 0;
        string result = "";
        for(char c:s){
            if(c=='('){
                if(level>0){
                    result+=c;
                }
                level++;
            }else{
                level--;
                if(level>0){
                    result+=c;
                }
            }
        }
        return result;
    }
};