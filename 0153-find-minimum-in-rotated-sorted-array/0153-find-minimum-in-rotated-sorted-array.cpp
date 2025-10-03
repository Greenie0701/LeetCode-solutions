class Solution {
public:
    int findMin(vector<int>& nums) {
        int low = 0;
        int high = nums.size()-1;
        int min_element = INT_MAX;
        while(low<=high){
            // Calculate the mid 
            int mid = low + (high-low) / 2;
            // Check if array is already sorted
            if(nums[low]<=nums[high]){
                min_element = min(min_element, nums[low]);
                break;
            }
            // [4,5,6,7,0,1,2,3]
            // Check which part of array is sorted
            if(nums[low]<=nums[mid]){
                min_element = min(min_element, nums[low]);
                low = mid+1;
            }else{
                high = mid-1;
                min_element = min(min_element, nums[mid]);
            }
        }
        return min_element;
    }
};