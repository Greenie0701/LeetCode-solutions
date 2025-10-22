class Solution {
public:
    int helper(string s, int i, long long num,int sign){
        if(i>=s.size() || !isdigit(s[i])){
            return int(num * sign);
        }
        num = num * 10 + (s[i]-'0');
        if((sign*num)>=INT_MAX)return INT_MAX;
        if((sign*num)<=INT_MIN)return INT_MIN;
        return helper(s, i+1, num, sign);
    }
    int myAtoi(string s) {
        // remove whitespaces
        int i=0;
        long long num = 0;
        int sign = 1;
        while(i<s.size() && s[i]== ' ')i++;
        // Predict the sign
        if(i<s.size() && (s[i]=='-'||s[i]=='+')){
            sign = s[i]=='-'?-1:1;
            i++;
        }
        return helper(s, i, num, sign);
    }
};