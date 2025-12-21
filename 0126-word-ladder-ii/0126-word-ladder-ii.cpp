class Solution {
public:
    unordered_map<string, int> mpp;
    vector<vector<string>> result;
    string b;

    void dfs(string word, vector<string>& seq){
        if(word==b){
            reverse(seq.begin(), seq.end());
            result.push_back(seq);
            reverse(seq.begin(), seq.end());
            return;
        }
        int step = mpp[word];
        for(int i=0; i<word.length(); i++){
            char org = word[i];
            for(char c='a'; c<='z'; c++){
                word[i]=c;
                if(mpp.find(word)!=mpp.end()&&mpp[word]+1==step){
                    seq.push_back(word);
                    dfs(word, seq);
                    seq.pop_back();
                }
                word[i] = org; 
            }
        }
    }

    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> s(wordList.begin(), wordList.end());
        queue<pair<string, int>> q;
        q.push({beginWord, 1});
        s.erase(beginWord);
        b=beginWord;
        int len = beginWord.length();
        mpp[beginWord]=1;
        int step = 1;
        while(!q.empty()){
            string word = q.front().first;
            step = q.front().second;
            q.pop();
            if(word==endWord){
                break;
            }
            for(int i=0; i<len; i++){
                char org = word[i];
                for(char c='a'; c<='z'; c++){
                    word[i] = c;
                    if(s.find(word)!=s.end()){
                        q.push({word, step+1});
                        s.erase(word);
                        mpp[word]=step+1;
                    }
                }
                word[i] = org;
            }
        }
        if(mpp.find(endWord)!=mpp.end()){
            vector<string> seq;
            seq.push_back(endWord);
            dfs(endWord, seq);
        }
        return result;
    }
};