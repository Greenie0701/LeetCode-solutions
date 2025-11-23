class Solution {
public:
    string removeOuterParentheses(string s) {
        // Level represent the nested paranthesis
        int level = 0;
        string ans = "";
        // Iterate through every character
        for(char ch : s){
            if(ch=='('){
                // Check if this is a primitive string
                if(level>0){
                    ans+=ch;
                }
                level++;
            }
            else if(ch==')'){
                //decrement the level 
                level--;
                if(level>0){
                    ans+=ch;
                }
            }
        }
        return ans;
    }
};