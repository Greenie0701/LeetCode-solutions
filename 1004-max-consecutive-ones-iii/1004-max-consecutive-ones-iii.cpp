class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int count = 0;
        int l =0;
        int r =0;
        int end=nums.size();
        int len = 0;
        while(r<end){
            if(nums[r]==0)count++;
            while(count>k){
                if(nums[l]==0)count--;
                l++;
            }
            len = max(len, (r-l+1));
            r++;
        }
        return len;
    }
};