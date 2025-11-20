class Solution {
public:
    string minWindow(string s, string t) {
        vector<int> hash(128, 0);
        int l = 0;
        int r =0;
        int mini = INT_MAX;
        int start =-1;
        int end = s.length();
        int n = t.length();
        int count = 0;
        for(int i=0; i<n; i++){
            hash[t[i]]++;
        }
        while(r<end){
            if(hash[s[r]]>0)count++;
            hash[s[r]]--;
            while(count==n){
                if(mini>(r-l+1)){
                    mini = r-l+1;
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