class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int N = nums.size();
        int sum = (N * (N+1))/2 ;
        int arrsum = 0;
        for(int i=0;i<N;i++){
            arrsum+=nums[i];
        }
        return(sum-arrsum);
    }
};