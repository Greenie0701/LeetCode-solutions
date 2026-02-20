class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n=nums.size();
        vector<int> result(n);
        for(int i=0; i<n; i++){
            nums[i] =nums[i]*nums[i];
            // [16,1,0,9,100]
            // [0,0,0,0,100]
        }
        int i=0;
        int j = n-1;
        int k = n-1;
        while(i<=j){
            if(i==j){
                result[k]=nums[i];
                break;
            }
            else if(nums[i]>nums[j]){
                result[k]=nums[i];
                i++;
                k--;
            }
            else{
                result[k] = nums[j];
                k--;
                j--;
            }
        }
        return result;
    }
};
