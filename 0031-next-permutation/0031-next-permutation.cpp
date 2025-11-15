class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        // Find the index where current index < index+1, break
        int index = -1;
        int size = nums.size();
        for(int i=size-2; i>=0; i--){
            if(nums[i]<nums[i+1]){
                index = i;
                break;
            }
        }
        // If no such index is found, just return the reverse of the array
        if(index==-1){
            reverse(nums.begin(), nums.end());
            return;
        }
        // Swap the index with first element from end where arr[index]<arr[i]
        for(int i=size-1; i>index; i--){
            if(nums[index]<nums[i]){
                swap(nums[i], nums[index]);
                break;
            }
        }
        // Reverse the array from [index+1] to n-1
        reverse(nums.begin() + index + 1, nums.end());
        return;
    }
};