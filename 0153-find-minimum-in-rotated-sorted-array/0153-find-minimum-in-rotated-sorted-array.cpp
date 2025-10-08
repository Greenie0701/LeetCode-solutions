class Solution {
public:
    int findMin(vector<int>& nums) {
        int min_element = INT_MAX;
        int low = 0;
        int high = nums.size()-1;
        if(nums[low]<=nums[high]){
            return nums[low];
        }
        while(low<=high){
            int mid = low + (high-low)/2;
            if(nums[low]<=nums[mid]){
                min_element = min(min_element, nums[low]);
                low = mid+1;
            }else{
                min_element = min(min_element, nums[mid]);
                high = mid -1;
            }
        }
        return min_element;
    }
};