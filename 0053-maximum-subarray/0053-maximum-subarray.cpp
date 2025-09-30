class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        // Kadane's Algorithm is a popular method to solve the Maximum Subarray Sum Problem,   
        int sum = 0;
        int maxsum = INT_MIN;
        
        // Iterate through the array 
        for(int i=0; i<nums.size(); i++){
            sum+=nums[i];
            maxsum=max(sum, maxsum);
            if(sum<0){
                sum = 0;
            }
        }
        return maxsum;
    }
};