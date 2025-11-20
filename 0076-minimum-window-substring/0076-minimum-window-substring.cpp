class Solution {
public:
    string minWindow(string s, string t) {
        int l = 0;
        int r = 0;
        int n= s.length();
        int m = t.length();
        int count =0;
        int mini = INT_MAX;
        int start = -1;
        vector<int> hash(128,0);
        // Precompute the hash map for string t(Required to track the number of elements in s of t)
        for(int i=0; i<m; i++){
            hash[t[i]]++;
        }
        while(r<n){
            // If the element is part of t, increment count
            if(hash[s[r]]>0)count++;
            // Decrement its count in hash, can be used to find its occurance in future;
            hash[s[r]]--;
            // Shrink the substring since you want to find the minimum length string
            while(count==m){
                if(mini>(r-l+1)){
                    mini = r-l+1;
                    start = l;
                }
                // Now shrink from the left;
                hash[s[l]]++; // This means we are removing from the substring
                if(hash[s[l]]>0)count--; // Need to find occurance of char at l in future
                l++; //move left front
            }
            r++;
        }
        return start==-1?"":s.substr(start, mini);
    }
};