class Solution {
public:
    bool canMakeSubsequence(string str1, string str2) {
        if(str2.length()>str1.length())return false;
        int n=str2.length();
        int j=0;
        for(char& ch:str1){
            if(j==n)break;

            if(ch==str2[j]||(ch!='z'&&str2[j]==ch+1)){
                j++;
            }
            else if(ch=='z'&&str2[j]=='a'){
                j++;
            }
            else{
                continue;
            }
        }
        return j==n;
    }
};