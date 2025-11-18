class Solution {
public:
    int characterReplacement(string s, int k) {
        int l =0;
        int r =0;
        vector<int> hash(26, 0);
        int end = s.length();
        int changes = 0;
        int maxi =0;
        int len = 0;
        while(r<end){
            hash[s[r]-'A']++;
            maxi=max(maxi, hash[s[r]-'A']);
            changes = (r-l+1)-maxi;
            if(changes>k){
                hash[s[l]-'A']--;
                l++;
            }
            if(changes<=k){
                len = max(r-l+1, len);
            }
            r++;
        }
        return len;
    }
};