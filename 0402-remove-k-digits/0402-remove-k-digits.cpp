class Solution {
public:
    string removeKdigits(string num, int k) {
        string s;
        if(k==num.length())return "0";
        for(int i=0; i<num.length(); i++){
            while(!s.empty()&&k>0&&s.back()-'0'>num[i]-'0'){
                s.pop_back();
                k--;
            }
            s.push_back(num[i]);
        }
        while(k>0){
            s.pop_back();
            k--;
        }
        int start = 0;
        while(start<s.length()&&s[start]=='0')start++;
        s = s.substr(start);
        return s.empty()?"0":s;
    }
};