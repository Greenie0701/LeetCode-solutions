class Solution {
public:
    int minimumPushes(string word) {
        int pushes=0;
        vector<int> freq(26, 0);
        for(char& ch:word){
            freq[ch-'a']++;
        }
        sort(freq.rbegin(), freq.rend());
        for(int i=0; i<26; i++){
            if(freq[i]==0)break;
            if(i<8){
                pushes+=freq[i];
            }
            else if(i<16){
                pushes+=(freq[i]*2);
            }
            else if(i<24){
                pushes+=(freq[i]*3);
            }
            else{
                pushes+=(freq[i]*4);
            }
        }
        return pushes;
    }
};