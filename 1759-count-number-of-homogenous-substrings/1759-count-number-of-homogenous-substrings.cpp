class Solution {
public:
    int countHomogenous(string s) {
        int n = s.length();
        if(n==1)return 1;
        int result = 0;
        int count = 0;
        int mod = 1e9+7;
        for(int i=0; i<n; i++){
            if(i>0&&s[i-1]==s[i]){
                count++;
            }
            else{
                count = 1;
            }
            result=((result+count)%mod);
        }
        return result;
    }
};