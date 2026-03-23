class Solution {
public:
    int maxScore(vector<int>& nums) {
        int maxi = INT_MIN;
        sort(nums.rbegin(), nums.rend());
        long long prefix = 0;
        int score = 0;
        for(int n:nums){
            prefix+=n;
            if(prefix>0){
                score++;
            }
            else{
                score=0;
            }
            maxi = max(maxi, score);
        }
        return maxi;
    }
};