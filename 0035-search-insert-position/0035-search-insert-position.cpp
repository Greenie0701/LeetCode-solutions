class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int low = 0;
        int high = nums.size()-1;
        int low_bound = nums.size();
        while(low<=high){
            int mid = low + (high-low)/2;
            if(nums[mid]>=target){
                low_bound = mid;
                high = mid -1;
            }else{
                low = mid+1;
            }
        }
        return low_bound;
    }
};