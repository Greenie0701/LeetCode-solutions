class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        int n = nums.size();
        vector<int> left_sum(n, 0);
        vector<int> right_sum(n, 0);
        vector<int> result;
        int leftsum=0;
        int rightsum=0;
        for(int i=0; i<n; i++){
            leftsum+=nums[i];
            rightsum+=nums[n-i-1];
            left_sum[i]=leftsum;
            right_sum[n-i-1]=rightsum;
        }
        for(int i=0; i<n; i++){
            if(i==0)result.push_back(abs((n-1)*(nums[i])-(right_sum[i]-nums[i])));
            else if(i==n-1)result.push_back(abs((n-1)*(nums[i])-(left_sum[i]-nums[i])));
            else result.push_back((nums[i] * i - left_sum[i - 1]) +(right_sum[i + 1] - nums[i] * (n - i - 1)));
        }
        return result;
    }
};