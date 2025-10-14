class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum = 0;
        int maxsum = INT_MIN;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            if(sum<0){
                maxsum = max(sum, maxsum);
                sum=0;
            }
            else{
                sum+=nums[i];
                maxsum=max(sum, maxsum);
            }
        }
        return maxsum;
    }
};