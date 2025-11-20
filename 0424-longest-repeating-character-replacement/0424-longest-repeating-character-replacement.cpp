class Solution {
public:
    int characterReplacement(string s, int k) {
        int maxf = 0;
        vector<int> hash(26, 0);
        int l=0;
        int r=0;
        int end = s.length();
        int maxi = 0;
        int changes =0;
        while(r<end){
            hash[s[r]-'A']++;
            maxf=max(maxf, hash[s[r]-'A']);
            changes = (r-l+1)-maxf;
            if(changes>k){
                hash[s[l]-'A']--;
                l++;
            }
            if(changes<=k){
                maxi = max(maxi, r-l+1);
            }
            r++;
        }
        return maxi;
    }
};