class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        // Find the first zero occuring element index in the array
        int zeroindex = -1;
        for(int j=0; j<nums.size()-1; j++){
            if(nums[j]==0){
                zeroindex=j;
                break;
            }
        }
        // Base case when no zero in the array
        if(zeroindex<0){
            return;
        }
        //Swap the non-zero element with zeroth index
        for(int j=zeroindex+1;j<nums.size();j++){
            if(nums[j]!=0){
                swap(nums[j],nums[zeroindex]);
                zeroindex++;
            }
        }

    }
};