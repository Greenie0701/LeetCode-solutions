class Solution {
public:

    unordered_map<string, int> transform;
    vector<vector<string>> result;
    string b;
    int len;

    void dfs(string word, vector<string>& seq){
        if(word==b){
            reverse(seq.begin(), seq.end());
            result.push_back(seq);
            reverse(seq.begin(), seq.end());
            return;
        }
        int step = transform[word];
        for(int i=0; i<len; i++){
            char ch = word[i];
            for(char c = 'a'; c<='z'; c++){
                word[i] = c;
                if(transform.find(word)!=transform.end()&&transform[word]+1==step){
                    seq.push_back(word);
                    dfs(word, seq);
                    seq.pop_back();
                }
            }
            word[i]=ch;
        }
    }

    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        b = beginWord;
        queue<pair<string, int>> q;
        q.push({beginWord, 0});
        unordered_set<string> s(wordList.begin(), wordList.end());
        s.erase(beginWord);
        transform[beginWord] = 0;
        len = beginWord.length();
        while(!q.empty()){
            string word = q.front().first;
            int st = q.front().second;
            q.pop();
            if(word==endWord)break;
            for(int i=0; i<len; i++){
                char ch = word[i];
                for(char c='a'; c<='z'; c++){
                    word[i] = c;
                    if(s.find(word)!=s.end()){
                        s.erase(word);
                        q.push({word, st+1});
                        transform[word] = st+1;
                    }
                }
                word[i] = ch;
            }
        }
        if(transform.find(endWord) != transform.end()){
            vector<string> seq;
            seq.push_back(endWord);
            dfs(endWord, seq);
        }

        return result;
    }
};