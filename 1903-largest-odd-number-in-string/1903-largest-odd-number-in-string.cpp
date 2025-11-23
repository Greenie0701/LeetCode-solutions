class Solution {
public:
    string largestOddNumber(string num) {
        int index = num.size()-1;
        while(index>=0){
            if(isdigit(num[index]))break;
            index--;
        }
        if(index<0){
            return "";
        }
        while(index>=0){
            if((num[index]-'0')%2==1)break;
            index--;
        }
        if(index<0){
            return "";
        }
        int start = 0;
        while(start<index){
            if(!isdigit(num[start])){
                start++;
            }else{
                break;
            }
        }
        return num.substr(start, index-start+1);
    }
};