class Solution {
public:
    int jump(vector<int>& nums) {
        int start = 0;
        int far = 0;
        int step = 0;
        for(int i=0; i<nums.size()-1; i++){
            far = max(far, i+nums[i]);
            if(i==start){
                step++;
                start = far;
            }
        }
        return step;
    }
};