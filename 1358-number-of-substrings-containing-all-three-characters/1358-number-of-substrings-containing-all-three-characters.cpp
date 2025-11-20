class Solution {
public:
    int numberOfSubstrings(string s) {
        vector<int> hash(3,0);
        int l = 0;
        int r = 0;
        int count =0;
        int end = s.length();
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