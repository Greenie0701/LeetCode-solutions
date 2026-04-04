class Solution {
public:
    int minDeletions(string s) {
        int ops = 0;
        vector<int> freq(26, 0);
        for(char& ch:s){
            freq[ch-'a']++;
        }
        sort(freq.rbegin(), freq.rend());
        int maxfreq = freq[0];
        for(int i=1; i<26; i++){
            if(freq[i]==0)break;
            int newfreq = freq[i];
            if(newfreq>=maxfreq){
                newfreq = max(maxfreq-1, 0);
                ops+=(freq[i]-newfreq);
            }
            maxfreq = newfreq;
        }
        return ops;
    }
};