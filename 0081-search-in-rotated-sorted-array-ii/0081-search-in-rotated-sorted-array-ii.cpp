class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int low = 0;
        int high = nums.size()-1;
        int k = target;
        while(low<=high){
            // Calculate the mid value, make sure not to occur any overflow
            int mid = low + (high-low)/2;
            // Check if the mid is actually the target
            if(nums[mid]==target){
                return true;
            }
            // Check if any duplicates exist, if yes skip
            if (nums[low] == nums[mid] && nums[mid] == nums[high]){
                low = low+1;
                high = high-1;
                continue;
            }
            // Check if the left half is sorted, then search in left half
            if(nums[low]<=nums[mid]){
                if(nums[low]<=k && k<nums[mid]){
                    high = mid-1;
                }else{
                    low = mid+1;
                }
            }
            // Check if the right half is sorted, then search in right half
            else if(nums[mid]<=nums[high]){
                if(k>nums[mid] && k<=nums[high]){
                    low = mid+1;
                }else{
                    high = mid-1;
                }
            }
        }
        return false;
    }
};