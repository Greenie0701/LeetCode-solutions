class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if(k==0||k==1)return 0;
        int mini = *min_element(nums.begin(), nums.end());
        int left = 0;
        int product=1;
        int count=0;
        for(int right=0; right<nums.size(); right++){
            product*=nums[right];
            while(product>=k){
                product=(product/nums[left]);
                left++;
            }
            count+=(right-left+1);
        }
        return count;
    }
};