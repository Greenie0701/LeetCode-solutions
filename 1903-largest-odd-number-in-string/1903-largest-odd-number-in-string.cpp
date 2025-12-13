class Solution {
public:
    string largestOddNumber(string num) {
        string result="";
        int index = num.length()-1;
        while(index>=0&&(isdigit(num[index])&&(num[index]-'0')%2!=1)){
            index--;
        }
        if(index<0){
            return result;
        }
        int start=0;
        while(start<index&&num[start]==' ')start++;
        result = num.substr(start, index-start+1);
        return result;
    }
};