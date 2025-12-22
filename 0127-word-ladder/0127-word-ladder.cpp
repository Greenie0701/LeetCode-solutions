class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        queue<pair<string, int>> q;
        q.push({beginWord, 1});
        unordered_set<string> s(wordList.begin(), wordList.end());
        s.erase(beginWord);
        int step = 0;
        int len = beginWord.length();
        if(s.find(endWord)==s.end())return step;
        while(!q.empty()){
            string word = q.front().first;
            step = q.front().second;
            q.pop();
            if(word==endWord){
                return step;
            }
            for(int i=0; i<len; i++){
                char ch = word[i];
                for(char c='a'; c<='z'; c++){
                    word[i] = c;
                    if(s.find(word)!=s.end()){
                        q.push({word, step+1});
                        s.erase(word);
                    }
                }
                word[i] = ch;
            }
        }
        return 0;
    }
};