class Solution {
public:
    string reverseWords(string s) {
        string result = "";
        string str = "";
        for(char c:s){
            if(c!=' '){
                str+=c;
            }
            else{
                if(!str.empty()){
                    result = result.empty()?str:str+' '+result;
                    str="";
                }
            }
        }
        if(!str.empty()){
            result=result.empty()?str:str+' '+result;
        }
        return result;
    }
};