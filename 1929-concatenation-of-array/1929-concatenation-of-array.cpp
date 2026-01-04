class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        /*
        nums  - length n
        ans - 2n
        ans[i] = nums
        ans[i+1] nums[i]
        */
        int len = nums.size();
        vector<int> ans(2*len);
        for(int i=0; i<len; i++){
            ans[i] = nums[i];
        }
        int j=0;
        for(int i=len; i<2*len; i++){
            ans[i] = nums[j];
            j++; 
        }
        return ans;
    }
};