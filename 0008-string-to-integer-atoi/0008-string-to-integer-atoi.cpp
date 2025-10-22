class Solution {
public:
    int recursiveatoi(string s, int i, long long num, int sign){
        // BaseCase
        if(i>=s.size() || !isdigit(s[i])){
            return (int)(num*sign);
        }
        num = num*10 + (s[i]-'0');
        if(sign * num>=INT_MAX)return INT_MAX;
        if(sign * num<=INT_MIN)return INT_MIN;
        return recursiveatoi(s, i+1, num, sign);
    }
    int myAtoi(string s) {
        int i=0;
        int sign = 1;
        // Check if the char is an empty
        while(i<s.size() && s[i]==' ')i++;
        // Predict the sign
        if(i<s.size() && (s[i] == '+' || s[i] == '-')){
            if(s[i]=='-'){
                sign = -1;
                i++;
            }
            else{
                i++;
            }
        }
        // Recursively extract the number from the string
        return recursiveatoi(s, i, 0, sign);
    }
};