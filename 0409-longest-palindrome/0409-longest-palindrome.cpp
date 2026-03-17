class Solution {
public:
    int longestPalindrome(string s) {
        // Track the frequencies of the char in the string
        vector<int> freq(128, 0);
        // Build the freq map
        for(char c:s){
            freq[c-'A']++;
        }
        // Track the even and odd length couples
        int length = 0;
        bool has_odd=false;
        for(auto v:freq){
            if(v!=0){
                if(v%2==0){
                    length+=v;
                }
                else{
                    length+=(v-1);
                    has_odd=true;
                }
            }
        }
        return has_odd?length+1:length;
    }
};