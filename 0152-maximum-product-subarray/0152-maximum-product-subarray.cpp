class Solution {
public:
    int maxProduct(vector<int>& nums) {
        // Initialise max value to INT_MIN
        int maxproduct = INT_MIN;
        // Initialise prefix and suffix to 1
        int prefix = 1;
        int suffix = 1;
        // Lets calculate the prefix and suffix product
        for(int i=0;i<nums.size();i++){
            // If my prefix/suffix becomes zero, just reset to 1
            if(prefix==0)prefix=1;
            if(suffix==0)suffix=1;
            //Calculate product from the prefix and suffix end
            prefix=prefix * nums[i];
            suffix=suffix * nums[nums.size()-i-1];
            // Update the maximum product
            maxproduct= max(maxproduct,max(prefix, suffix));
        }
        return maxproduct;
    }
};