class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l = 0;
        int r = 0;
        vector<int> m(256, -1);
        int len = 0;
        int end = s.size();
        while(r<end){
            if(m[s[r]]!=-1){
                l = max(l, m[s[r]]+1);
            }
            m[s[r]] = r;
            len = max(len, r-l+1);
            r++;
        }
        return len;
    }
};