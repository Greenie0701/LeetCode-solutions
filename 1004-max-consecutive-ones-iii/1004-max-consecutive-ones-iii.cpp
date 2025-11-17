class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int count =0;
        int l =0;
        int r=0;
        int end = nums.size();
        int maxi = 0;
        while(r<end){
            if(nums[r]==0)count++;
            if(count>k){
                if(nums[l]==0)count--;
                l++;
            }
            if(count<=k){
                maxi = max(maxi, r-l+1);
            }
            r++;
        }
        return maxi;
    }
};