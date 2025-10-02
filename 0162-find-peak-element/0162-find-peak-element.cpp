class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int low = 0;
        int high= nums.size()-1;
        int peak;
        // Peak element is an element in a given array, where its 
        // adjacent elements are lesser

        // log n which means binary search
        while(low<=high){
            // Calculate the mid
            int mid = low + (high - low)/2;

            // Check whether the peak occurs left i.e m < m-1
            if(mid>0 && nums[mid]<nums[mid-1]){
                high = mid-1;
            }
            // Check whether the peak occurs left i.e m < m+1
            else if(mid<high && nums[mid]<nums[mid+1]){
                low = mid+1;
            }
            // My mid is actually greater than both ends
            else{
                peak = mid;
                break;
            }
        }
        return peak;
    }
};