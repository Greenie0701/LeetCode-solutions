class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set s(wordList.begin(), wordList.end());
        queue<pair<string, int>> q;
        q.push({beginWord, 1});
        s.erase(beginWord);
        while(!q.empty()){
            string word = q.front().first;
            int step = q.front().second;
            q.pop();
            if(word==endWord){
                return step;
            }
            for(int i=0; i<word.length(); i++){
                char org = word[i];
                for(char c ='a'; c<='z'; c++){
                    word[i]=c;
                    if(s.find(word)!=s.end()){
                        q.push({word, step+1});
                        s.erase(word);
                    }
                }
                word[i]=org;
            }
        }
        return 0;
    }
};