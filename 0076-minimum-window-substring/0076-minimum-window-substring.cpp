class Solution {
public:
    string minWindow(string s, string t) {
        int size = s.length();
        int m = t.length();
        int mini = INT_MAX;
        int start = -1;
        for(int i =0; i<size; i++){
            vector<int> hash(128, 0);
            int count = 0;
            for(int j=0; j<m; j++){
                hash[t[j]]++;
            }
            for(int k=i; k<size; k++){
                if(hash[s[k]]>0)count++;
                hash[s[k]]--;
                if(count==m){
                    mini = min(mini, k-i+1);
                    start = i;
                    break;
                }
            }
        }
        return start==-1?"":s.substr(start, mini);
    }
};