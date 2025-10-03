class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        // Handle the edge cases 
        int n = nums.size();
        if(n==1){
            return nums[0];
        }
        // My starting element is unique
        if(nums[0]!=nums[1]){
            return nums[0];
        }
        // Check the last two elements(Avoids out of bounds)
        if(nums[n-2]!=nums[n-1]){
            return nums[n-1];
        }

        int low = 1;
        int high = n-2;
        while(low<=high){
            int mid = low + (high - low)/2;
            // Base case
            if((nums[mid]!=nums[mid+1])&&(nums[mid]!=nums[mid-1])){
                return nums[mid];
            }
            // Check if mid is even, if yes -> my next neighbour should equal
            // or if mid is odd, if yes -> my prev neighbour should equal
            // if any one of the case is true, then my unique should present in the right half
            else if((mid % 2 ==0 && nums[mid]==nums[mid+1])|| (mid % 2 ==1 && nums[mid]==nums[mid-1])){
                low = mid+1;
            }
            // Else my unique is present in left
            else{
                high = mid -1;
            }
        }
        return -1;
    }
};