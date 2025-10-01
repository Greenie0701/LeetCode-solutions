class Solution {
public:
    int binary_search(vector<int>& nums, int low, int high, int target) {
        if (low > high) {
            return -1;
        }
        int mid = low + (high - low) / 2;  // ✅ Correct midpoint formula

        if (nums[mid] == target) {
            return mid;
        } else if (nums[mid] < target) {
            return binary_search(nums, mid + 1, high, target);  // search right
        } else {
            return binary_search(nums, low, mid - 1, target);   // search left
        }
    }

    int search(vector<int>& nums, int target) {
        return binary_search(nums, 0, nums.size() - 1, target);
    }
};
