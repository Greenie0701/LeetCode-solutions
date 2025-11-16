class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.empty()){
            return 0;
        }
        int max_len=INT_MIN;
        for(int i=0; i<s.size(); i++){
            unordered_map<char, int> mpp;
            int len = 0;
            for(int j=i; j<s.size();j++){
                if(mpp[s[j]]==1)break;
                len = j-i+1;
                max_len = max(max_len, len);
                mpp[s[j]]++;
            }
        }
        return max_len;
    }
};