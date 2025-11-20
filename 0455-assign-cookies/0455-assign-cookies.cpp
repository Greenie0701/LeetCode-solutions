class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int l = 0;
        int r = 0;
        int m = g.size();
        int n = s.size();
        int count=0;
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        while(l<n && r<m){
            if(s[l]>=g[r]){
                count++;
                r++;
            }
            l++;
        }
        return count;
    }
};