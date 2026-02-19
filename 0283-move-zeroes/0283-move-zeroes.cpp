class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int zero = -1;
        int n = nums.size();
        for(int i=0; i<n; i++){
            if(nums[i]==0){
                zero=i;
                break;
            }
        }
        if(zero==-1)return;
        for(int i=zero+1; i<n; i++){
            if(nums[i]!=0){
                swap(nums[i], nums[zero]);
                zero++;
            }
        }
    }
};