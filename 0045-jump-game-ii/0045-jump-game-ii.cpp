class Solution {
public:
    int jump(vector<int>& nums) {
        int n=nums.size();
        // Check if you have only one step
        if(n==1)return 1;
        if(n==1&&nums[0]==0)return 0;
        // Steps tracks the minimum steps to reach final index
        int steps =0;
        // Start tracks the starting index in the range
        int start=0;
        // far tracks the end of the range
        int far =0;
        for(int i=0; i<n-1; i++){
            far = max(far, i+nums[i]);
            if(i==start){
                start = far;
                steps++;
            }
        }
        return steps;
    }
};
