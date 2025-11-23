class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if(s.length()!=t.length()){
            return false;
        }
        vector<int> hash1(256,-1);
        vector<int> hash2(256,-1);
        for(int i=0; i<s.length(); i++){
            if(hash1[s[i]]!=hash2[t[i]]){
                return false;
            }
            hash1[s[i]]=i;
            hash2[t[i]]=i;
        }
        return true;
    }
};