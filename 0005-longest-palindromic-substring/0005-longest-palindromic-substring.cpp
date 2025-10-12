class Solution {
public:
    string longestPalindrome(string s) {
        int len = 0;
        string result = "";
        // Handle the odd length and even length longest palindrome string
        for(int i=0; i<s.length(); i++){
            // handle the odd length palindrome string
            int l = i;
            int r = i;
            while(l>=0 && r<s.length() && s[l]==s[r]){
                if(len<r-l+1){
                    len = r-l+1;
                    result = s.substr(l,len);
                }
                l--;
                r++;
            }
            // handle the even length palindrome string
            int l1 = i;
            int r2 = i+1;
            while(l1>=0 && r2<s.length() && s[l1]==s[r2]){
                if(len<r2-l1+1){
                    len = r2-l1+1;
                    result = s.substr(l1,len);
                }
                l1--;
                r2++;
            }
        }
        return result;
    }
};