class Solution {
public:
    string removeKdigits(string num, int k) {
        string s;
        if(num.length()==k){
            return "0";
        }
        for(int i=0; i<num.length();i++){
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
        int index = 0;
        while(index<s.length()&&s[index]=='0')index++;
        s =s.substr(index);
        return s.empty()?"0":s;
    }
};