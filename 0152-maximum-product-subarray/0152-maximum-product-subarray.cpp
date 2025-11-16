class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int prefix_prod = 1;
        int suffix_prod = 1;
        int last = nums.size()-1;
        int maxprod = INT_MIN;
        for(int i=0; i<nums.size(); i++){
            prefix_prod*=nums[i];
            suffix_prod*=nums[last-i];
            maxprod = max(maxprod, max(suffix_prod, prefix_prod));
            if(prefix_prod==0)prefix_prod=1;
            if(suffix_prod==0)suffix_prod=1;
        }
        return maxprod;
    }
};