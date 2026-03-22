class Solution {
public:
    int minimumPushes(string word) {
        vector<int> freq(26, 0);
        for(char& c:word){
            freq[c-'a']++;
        }
        sort(freq.rbegin(), freq.rend());
        int pushes=0;
        for(int i=0; i<26; i++){
            if(freq[i]==0)break;
            else if(i<8)pushes+=freq[i];
            else if(i<16)pushes+=(2*freq[i]);
            else if(i<24)pushes+=(3*freq[i]);
            else pushes+=(4*freq[i]);
        }
        return pushes;
    }
};