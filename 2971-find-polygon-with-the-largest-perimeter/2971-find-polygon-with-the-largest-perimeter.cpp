class Solution {
public:
    long long largestPerimeter(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        long long sum = 0;
        long long result = -1;

        for (int x : nums) {
            sum += x;

            if (sum - x > x) {
                result = sum;
            }
        }

        return result;
    }
};