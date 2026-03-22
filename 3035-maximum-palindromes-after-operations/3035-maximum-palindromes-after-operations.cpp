class Solution {
public:
    int maxPalindromesAfterOperations(vector<string>& words) {
        vector<int> length;
        vector<int> freq(26, 0);
        for(string& word:words){
            length.push_back(word.length());
            for(char& c:word){
                freq[c-'a']++;
            }
        }
        int count=0;
        int pair=0;
        for(int& f:freq){
            pair+=(f/2);
        }
        sort(length.begin(), length.end());
        for(int& l:length){
            int needed = l/2;
            if(pair>=needed){
                pair-=needed;
                count++;
            }
        }
        return count;
    }
};