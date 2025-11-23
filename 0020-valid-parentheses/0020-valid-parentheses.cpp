class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for(char c:s){
            if(c=='('||c=='{'||c=='['){
                st.push(c);
            }else{
                if(st.empty())return false;
                char ch = c;
                char top = st.top();
                st.pop();
                if(ch==')' && top!='(')return false;
                if(ch==']' && top!='[')return false;
                if(ch=='}' && top!='{')return false;
            }
        }
        return(st.empty());
    }
};