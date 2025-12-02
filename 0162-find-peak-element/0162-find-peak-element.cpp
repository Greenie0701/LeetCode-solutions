class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int low = 0;
        int high = nums.size()-1;
        while(low<=high){
            int mid = low+(high-low)/2;

            int left = mid-1<0?INT_MIN:nums[mid-1];
            int right = mid+1<nums.size()?nums[mid+1]:INT_MIN;

            if(left<nums[mid]&&right<nums[mid]){
                return mid;
            }
            else if(left>nums[mid]){
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }
        return -1;
    }
};