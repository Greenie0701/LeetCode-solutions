class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l = 0;
        unordered_map<int, int> m;
        int r =0;
        int end = s.length();
        int len = 0;
        while(r<end){
            if(m.find(s[r]-'a')!=m.end()){
                l = max(l, m[s[r]-'a']+1);
            }
            m[s[r]-'a'] = r;
            len = max(len, r-l+1);
            r++;
        }
        return len;
    }
};