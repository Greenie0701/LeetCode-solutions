class Solution {
public:
    int minDeletions(string s) {
        vector<int> freq(26, 0);
        for(char& c:s){
            freq[c-'a']++;
        }
        sort(freq.rbegin(), freq.rend());
        int max_freq = freq[0];
        int new_freq = 0;
        int ops = 0;
        for(int i=1; i<26; i++){
            if(!freq[i])break;
            new_freq = freq[i];
            if(freq[i]>=max_freq){
                new_freq = max(max_freq-1, 0);
                ops+=(freq[i]-new_freq);
            }
            max_freq = new_freq;
        }
        return ops;
    }
};