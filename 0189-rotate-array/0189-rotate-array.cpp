class Solution {
public:
    void reverse(int start, int end, vector<int>& nums){
        while(start<end){
            swap(nums[start], nums[end]);
            start++;
            end--;
        }
    }
    void rotate(vector<int>& nums, int k) {
        int size=nums.size();
        k = k%size;
        reverse(0,size-k-1,nums);
        reverse(size-k, size-1, nums);
        reverse(0,size-1,nums);
    }
};