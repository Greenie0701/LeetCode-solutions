class Solution {
public:
    int rob(vector<int>& nums) {
        int prev = nums[0];
        int prev2 = 0;
        for(int i=1; i<nums.size(); i++){
            int pick = nums[i];
            if(i>1)pick+=prev2;
            int not_pick = prev;
            int curr = max(pick, not_pick);
            prev2 = prev;
            prev = curr;
        }
        return prev;
    }
};