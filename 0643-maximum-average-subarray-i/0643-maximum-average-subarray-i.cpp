class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        if(nums.size()<k)return 0.0;
        double maxi = 0;
        double win_sum=0;
        // Find the maximum average for firsk k size windows
        for(int i=0; i<k; i++){
            win_sum+=nums[i];
        }
        maxi = win_sum/k;
        // Slide the window to get the sum
        for(int i=k; i<nums.size(); i++){
            win_sum+=(nums[i]-nums[i-k]);
            maxi = max(maxi, win_sum/k);
        }
        return maxi;
    }
};
