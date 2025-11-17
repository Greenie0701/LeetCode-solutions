class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int l = 0;
        int r = 0;
        int size = nums.size();
        int zero =0;
        int maxi = 0;
        while(r<size){
            if(nums[r]==0)zero++;
            while(zero>k){
                if(nums[l]==0)zero--;
                l++;
            }
            if(zero<=k){
                maxi = max(maxi, r-l+1);
            }
            r++;
        }
        return maxi;
    }
};