class Solution {
public:
    int maxOperations(string s) {
        int ops = 0;
        int ones = 0;
        for(int i=0; i<s.length(); i++){
            if(s[i]=='1'){
                ones++;
            }
            else{
                while(i+1<s.length()&&s[i+1]=='0'){
                    i++;
                }
                ops+=ones;
            }
        }
        return ops;
    }
};