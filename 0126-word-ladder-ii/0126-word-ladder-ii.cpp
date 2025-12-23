class Solution {
public:

    vector<vector<string>> result;
    unordered_map<string, int> transform;
    int len;
    string b;

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
            for(char c='a'; c<='z'; c++){
                word[i] = c;
                if(transform.find(word)!=transform.end()&&transform[word]+1==step){
                    seq.push_back(word);
                    dfs(word, seq);
                    seq.pop_back();
                }
            }
            word[i] = ch;
        }
    }

    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        // Queue to perform BFS
        queue<pair<string, int>> q;
        // Set to track unique set of transforms
        unordered_set<string> s(wordList.begin(), wordList.end());
        // If no endword found, no transformation possible, so return earlier
        if(s.find(endWord)==s.end())return result;
        // Start with the beginWord
        q.push({beginWord, 0});
        // Mark the level
        transform[beginWord] = 0;
        // Remove the word from set to avoid duplicate transformations
        s.erase(beginWord);
        // Get the len of the word
        len = beginWord.length();
        b = beginWord;
        // Perform BFS
        while(!q.empty()){
            string word = q.front().first;
            int step = q.front().second;
            q.pop();
            // Any where you find the endword pls break this
            // Try replacing every char in the word and check it is valid possible transformation
            for(int i=0; i<len; i++){
                // Save the org char
                char ch = word[i];
                for(char c='a'; c<='z'; c++){
                    word[i] = c;
                    if(s.find(word)!=s.end()){
                        q.push({word, step+1});
                        s.erase(word);
                        transform[word] = step+1;
                    }
                }
                word[i] = ch;
            }
        }

        if(transform.find(endWord)!=transform.end()){
            vector<string> seq;
            seq.push_back(endWord);
            dfs(endWord, seq);
        }

        return result;
    }
};