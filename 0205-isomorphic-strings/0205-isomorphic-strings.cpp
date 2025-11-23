class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if(s.length()!=t.length()){
            return false;
        }
        vector<int> freq1(256, -1);
        vector<int> freq2(256, -1);
        for(int i=0; i<s.length(); i++){
            if(freq1[s[i]]!=freq2[t[i]]){
                return false;
            }
            freq1[s[i]]=i;
            freq2[t[i]]=i;
        }
        return true;
    }
};