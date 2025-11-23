class Solution {
public:
    bool isIsomorphic(string s, string t) {
        vector<int> hashs(256, -1);
        vector<int> hasht(256, -1);
        if(s.length()!=t.length()){
            return false;
        }
        for(int i=0; i<s.length(); i++){
            if(hashs[s[i]]!=hasht[t[i]]){
                return false;
            }
            hashs[s[i]]=i;
            hasht[t[i]]=i;
        }
        return true;
    }
};