class Solution {
public:
    int maxScore(vector<int>& nums) {

        sort(nums.rbegin(), nums.rend());
        long long prefix = 0;
        int score = 0;
        for(int n:nums){
            prefix+=n;
            if(prefix>0){
                score++;
            }
            else{
                
                break;
            }

        }
        return score;
    }
};