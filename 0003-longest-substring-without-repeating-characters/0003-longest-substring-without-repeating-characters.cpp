class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l=0;
        int r=0;
        int end = s.length();
        int len = 0;
        vector<int> hash(256, -1);
        while(r<end){
            if(hash[s[r]]>-1){
                l = max(l, hash[s[r]]+1);
            }
            hash[s[r]] = r;
            len = max(len, r-l+1);
            r++;
        }
        return len;
    }
};