class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int size = nums.size();
        vector<int> ans(size,0);
        int neg = 1;
        int pos = 0; 
        for(int i=0;i<size;i++){
            if(nums[i]<0){
                ans[neg] = nums[i];
                neg+=2;
            }
            else{
                ans[pos]=nums[i];
                pos+=2;
            }
        }
        return ans;
    }
};