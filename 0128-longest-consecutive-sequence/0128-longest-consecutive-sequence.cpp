class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s(nums.begin(), nums.end());
        int maxi = 0;
        for(int n:s){
            int len = 0;
            if(s.find(n-1)==s.end()){
                while(s.find(n+len)!=s.end()){
                    len++;
                }
            }
            maxi =max(len, maxi);
        }
        return maxi;
    }
};