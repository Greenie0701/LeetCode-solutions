class Solution {
public:
    int search(vector<int>& nums, int target) {
        int low = 0;
        int high= nums.size()-1;
        int result = -1;
        while(low<=high){
            // Avoid overflow in the mid calculation
            int mid = low+(high-low)/2;
            // The target has found, break out of the loop
            if(nums[mid]==target){
                result = mid;
                break;
            }
            if(nums[low]<=nums[mid]){
                if(nums[low]<=target && target<=nums[mid]){
                    high = mid-1;
                }else{
                    low = mid+1;
                }
            }else{
                if(nums[mid]<=target && target<=nums[high]){
                    low=mid+1;
                }else{
                    high=mid-1;
                }
            }

        } 
        return result;
    }
};