class Solution {
public:
    bool check_possible(vector<int>& nums, int mid, int k){
        int count_subarray = 1;
        int sum = 0;
        for(int i=0; i<nums.size(); i++){
            if(sum+nums[i]<=mid){
                sum+=nums[i];
            }
            else{
                count_subarray++;
                sum=nums[i];
            }
        }
        if(count_subarray<=k){
            return true;
        }else{
            return false;
        }
    }
    int splitArray(vector<int>& nums, int k) {
        int low = *max_element(nums.begin(), nums.end());
        int high = accumulate(nums.begin(), nums.end(), 0);
        while(low<=high){
            int mid = low+(high-low)/2;

            if(check_possible(nums, mid, k)){
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }
        return low;
    }
};