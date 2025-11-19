class Solution {
public:
    string minWindow(string s, string t) {
        int m = t.length();
        int n = s.length();
        vector<int> hash(256, 0);
        int mini = INT_MAX;
        int count=0;
        int l =0;
        int r =0;
        int start =-1;
        for(int i=0; i<m; i++){
            hash[t[i]]++;
        }
        while(r<n){
            if(hash[s[r]]>0)count++;
            hash[s[r]]--;
            while(count==m){
                if((r-l+1)<mini){
                    start = l;
                    mini = r-l+1;
                }
                hash[s[l]]++;
                if(hash[s[l]]>0)count--;
                l++;
            }
            r++;
        }
        return start==-1?"":s.substr(start, mini);
    }
};