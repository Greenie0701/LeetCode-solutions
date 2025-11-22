class Solution {
public:
    string minWindow(string s, string t) {
        int count=0;
        int mini=INT_MAX;
        vector<int> hash(128, 0);
        int l1 = s.length();
        int l2 = t.length();
        int start = -1;
        int l=0;
        int r=0;
        int end = s.length();
        for(int i=0; i<l2; i++){
            hash[t[i]]++;
        }
        while(r<end){
            if(hash[s[r]]>0)count++;
            hash[s[r]]--;
            while(count==l2){
                if(mini>(r-l+1)){
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