class Solution {
public:
    int numberOfSubstrings(string s) {
        int l = 0;
        int r = 0;
        vector<int> hash(3,0);
        int end = s.length();
        int count =0;
        while(r<end){
            hash[s[r]-'a']++;
            while(hash[0]>0&&hash[1]>0&&hash[2]>0){
                count+=end-r;
                hash[s[l]-'a']--;
                l++;
            }
            r++;
        }
        return count;
    }
};