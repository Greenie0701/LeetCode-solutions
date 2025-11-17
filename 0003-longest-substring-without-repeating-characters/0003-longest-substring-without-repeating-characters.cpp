class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l =0;
        int r=0;
        int end = s.size();
        int len =0;
        vector<int> mpp(256, -1);
        if(s.empty()){
            return 0;
        }
        while(r<end){
            if(mpp[s[r]]!=-1){
                l = max(l, mpp[s[r]]+1);
            }
            mpp[s[r]] = r;
            len = max(len, r-l+1);
            r++;
        }
        return len;
    }
};