class Solution {
public:
    bool isIsomorphic(string s, string t) {
        // Base case check whether both arrays are in same size
        if(s.length()!=t.length()){
            return false;
        }
        // Use ascii array to track the elements occurance
        int m1[256] = {0};
        int m2[256] = {0};
        // Iterate through every element
        for(int i=0;i<=s.length()-1;i++){
            if(m1[s[i]]!=m2[t[i]]){
                return false;
            }
            m1[s[i]] = i+1;
            m2[t[i]] = i+1;
        }
        return true;
    }
};