class Solution {
public:
    int minDeletions(string s) {
        vector<int> freq(26, 0);
        for(char& c:s){
            freq[c-'a']++;
        }
        sort(freq.rbegin(), freq.rend());
        int max_freq = freq[0];
        int ops = 0;
        for(int i=1; i<26; i++){
            if(freq[i]==0)break;
            if(freq[i]>=max_freq){
                int new_freq = max(0, max_freq-1);
                ops+=freq[i]-new_freq;
                freq[i]=new_freq;
            }
            max_freq=freq[i];
        }
        return ops;
    }
};