class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        if (nums.size() == 1) {
            return 0;
        }

        int low = 0;
        int high = nums.size() - 1;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            int left = (mid - 1 >= 0) ? nums[mid - 1] : INT_MIN;
            int right = (mid + 1 < nums.size()) ? nums[mid + 1] : INT_MIN;

            if (nums[mid] > left && nums[mid] > right) {
                return mid;
            } else if (nums[mid] < right) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        return -1;
    }
};
