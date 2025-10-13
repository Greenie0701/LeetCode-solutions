class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if(nums.size()==1){
            return nums[0];
        }
        int size = nums.size();
        int prefix = 1;
        int suffix = 1;
        int maxi = INT_MIN;
        for(int i=0;i<size;i++){
            if(prefix==0)prefix=1;
            if(suffix==0)suffix=1;
            prefix = prefix*nums[i];
            suffix = suffix*nums[size-1-i];
            maxi = max(maxi, max(prefix, suffix));
        }
        return maxi;
    }
};