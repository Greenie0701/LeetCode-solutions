class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> mpp(256, -1);
        int max_len = 0;
        int l=0;
        int r=0;
        int end = s.length();
        while(r<end){
            if(mpp[s[r]]!=-1){
                l = max(mpp[s[r]]+1, l);
            }
            mpp[s[r]] = r;
            max_len = max(max_len, r-l+1);
            r++;
        }
        return max_len;
    }
};