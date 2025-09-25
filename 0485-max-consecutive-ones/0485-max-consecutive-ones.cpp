class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        // Initialise the count to track current cons 1's seq
        // Maxcount to track highest cons 1's seq
        int maxcount = 0;
        int count = 0;
        // Iterate through the array
        for(int i=0;i<nums.size();i++){
            // Check the current element is zero, then increase count
            if(nums[i]==1){
                count++;
            }
            // So the handle the break in seq, find the maxcount and initialise count as zero to track next cons 1's seq
            else{
                maxcount=max(maxcount, count);
                count=0;
            }
        }
        maxcount = max(maxcount, count);
        return maxcount;
    }
};