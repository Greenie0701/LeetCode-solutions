class Solution {
public:
    int longestPalindrome(string s) {
        vector<int> freq(128, 0);
        bool hasOddFrequency = false;
        for(char c:s){
            freq[c]++;
        }
        int result = 0;
        for(auto it:freq){
            int val = it;
            if(val==0)continue;
            else if(val%2==0)result+=val;
            else{
                result+=(val-1);
                hasOddFrequency = true;
            }
        }
        return hasOddFrequency?result+1:result;
    }
};