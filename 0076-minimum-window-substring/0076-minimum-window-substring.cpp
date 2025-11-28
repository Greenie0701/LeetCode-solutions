class Solution {
public:
    string minWindow(string s, string t) {
        if(s.length()<t.length()){
            return("");
        }
        int l = 0;
        int r = 0;
        int lens = s.length();
        int lent = t.length();
        int start = -1;
        int mini = INT_MAX;
        int count = 0;
        vector<int> hash(128, 0);
        for(int i=0; i<lent; i++){
            hash[t[i]]++;
        }
        while(r<lens){
            if(hash[s[r]]>0)count++;
            hash[s[r]]--;
            while(count==lent){
                if((r-l+1)<mini){
                    mini = (r-l+1);
                    start = l;
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