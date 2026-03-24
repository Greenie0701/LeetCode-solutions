class Solution {
public:
    int maxPalindromesAfterOperations(vector<string>& words) {
        vector<int> len;
        vector<int> freq(26, 0);
        for(string& word:words){
            len.push_back(word.length());
            for(char& ch:word){
                freq[ch-'a']++;
            }
        }
        int pair=0;
        for(int& f:freq){
            if(!f)continue;
            pair+=(f/2);
        }
        int count=0;
        sort(len.begin(), len.end());
        for(int& l:len){
            if(pair>=(l/2)){
                count++;
                pair-=(l/2);
            }
        }
        return count;
    }
};