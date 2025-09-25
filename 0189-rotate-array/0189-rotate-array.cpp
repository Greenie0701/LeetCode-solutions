class Solution {
public:
    void reverse(vector<int>& nums, int start, int end){
        int temp=0;
        while(start<end){
            temp = nums[start];
            nums[start]=nums[end];
            nums[end]=temp;
            start++;
            end--;
        }
    }
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        // Base case when array size contains one element
        if(n==0){
            return;
        }
        // Find the  number of rotations which are required
        k=k%n; 
        /* To rotate array by k positions, you may have perform the following operations:
           1. Reverse elements in array from 0 to n-k-1
           2. Reverse elements in array from n-k to n-1
           3. Reverse elements in array from 0 to n-1(complete array)
        */ 
        reverse(nums, 0, n-k-1);
        reverse(nums, n-k, n-1);
        reverse(nums, 0, n-1);
    }
};