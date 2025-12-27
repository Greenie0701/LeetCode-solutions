class Solution {
public:
    vector<vector<string>> result;
    unordered_map<string, int> m;
    int len;
    string b;

    void dfs(string word, vector<string>& seq){
        if(word==b){
            reverse(seq.begin(), seq.end());
            result.push_back(seq);
            reverse(seq.begin(), seq.end());
            return;
        }
        int step = m[word];
        for(int i=0; i<len; i++){
            char ch = word[i];
            for(char c = 'a'; c<='z'; c++){
                word[i] = c;
                if(m.find(word)!=m.end()&&m[word]+1==step){
                    seq.push_back(word);
                    dfs(word, seq);
                    seq.pop_back();
                }
            }
            word[i] = ch;
        }
    }

    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> s(wordList.begin(), wordList.end());
        queue<pair<string, int>> q;
        q.push({beginWord, 0});
        m[beginWord] = 0;
        b = beginWord;
        s.erase(beginWord);
        len = beginWord.size();
        while(!q.empty()){
            string word = q.front().first;
            int step = q.front().second;
            q.pop();
            if(word==endWord)break;
            for(int i=0; i<len; i++){
                char ch = word[i];
                for(char c = 'a'; c<='z'; c++){
                    word[i] = c;
                    if(s.find(word)!=s.end()){
                        q.push({word, step+1});
                        s.erase(word);
                        m[word] = step+1;
                    }
                }
                word[i] = ch;
            }
        }
        vector<string> seq;
        if(m.find(endWord)!=m.end()){
            seq.push_back(endWord);
            dfs(endWord, seq);
        }
        return result;
    }
};