class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l=0;
        int r=0;
        int size =s.length();
        int len=0;
        vector<int> hash(256, -1);
        while(r<size){
            if(hash[s[r]]!=-1){
                l = max(hash[s[r]]+1,l);
            }
            hash[s[r]]=r;
            len = max(len, r-l+1);
            r++;
        }
        return len;
    }
};