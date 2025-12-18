class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        set<string> wordset(wordList.begin(), wordList.end());
        queue<pair<string, int>> q;
        q.push({beginWord, 1});
        wordset.erase(beginWord);
        while(!q.empty()){
            int step = q.front().second;
            string word = q.front().first;
            q.pop();
            if(word==endWord){
                return step;
            }
            for(int i=0; i<word.length(); i++){
                char org = word[i];
                for(char c='a'; c<='z'; c++){
                    word[i] = c;
                    if(wordset.find(word)!=wordset.end()){
                        q.push({word, step+1});
                        wordset.erase(word);
                    }
                }
                word[i]=org;
            }
        }
        return 0;
    }
};