class Solution {
public:
    long long minimumOperations(vector<int>& nums, vector<int>& target) {
        long long ops = 0;
        int n = nums.size();
        vector<int> diff(n);
        for(int i=0; i<n; i++){
            diff[i] = target[i]-nums[i];
        }
        ops+=abs(diff[0]);
        for(int i=1; i<n; i++){
            // Check if the current is a peak
            if(diff[i]>=0&&diff[i-1]>=0){
                ops+=max(0, diff[i] - diff[i - 1]);
            }
            // What if both are decreasing
            else if(diff[i]<=0&&diff[i-1]<=0){
                ops+=max(abs(diff[i]) - abs(diff[i - 1]), 0);
            }
            // else if decreasing or increasing , you seperate ops
            else{
                ops+=abs(diff[i]);
            }
        }
        return ops;
    }
};