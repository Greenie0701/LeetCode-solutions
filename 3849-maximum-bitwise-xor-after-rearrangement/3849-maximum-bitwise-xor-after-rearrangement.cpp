class Solution {
public:
    string maximumXor(string s, string t) {
        int one = 0;
        int zero = 0;
        for(char c:t){
            if(c=='1')one++;
            else zero++;
        }
        string maxi="";
        for(char c:s){
            if(c=='1'){
                if(zero>0){
                    maxi+="1";
                    zero--;
                }
                else{
                    maxi+="0";
                    one--;
                }
            }
            else{
                if(one>0){
                    one--;
                    maxi+="1";
                }
                else{
                    zero--;
                    maxi+="0";
                }
            }
        }
        return maxi;
    }
};

// 0 - 0
// 1 - 1

// 110

/*
0110 1110

1-0
0-0

1101
*/