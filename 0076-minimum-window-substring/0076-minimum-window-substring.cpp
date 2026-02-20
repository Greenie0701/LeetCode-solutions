class Solution {
public:
    string minWindow(string s, string t) {
        int m = s.length();
        int n = t.length();
        vector<int> hash(128, 0);
        int mini = INT_MAX;
        int start = -1;
        int count = 0;
        for(char c:t){
            hash[c]++;
        }
        int l=0; int r=0;
        while(r<m){
            if(hash[s[r]]>0)count++;
            hash[s[r]]--;
            while(count==n){
                if(r-l+1<mini){
                    start = l;
                    mini = r-l+1;
                }
                hash[s[l]]++;
                if(hash[s[l]]>0)count--;
                l++;
            }
            r++;
        }
        return start<0?"":s.substr(start, mini);
    }
};