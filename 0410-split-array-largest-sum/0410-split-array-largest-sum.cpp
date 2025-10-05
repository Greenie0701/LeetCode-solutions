class Solution {
public:
    int partition(vector<int>& nums, int size, int maxsum) {
        int partitions = 1;
        long long subarraysum = 0;
        for (int num : nums) {
            if (subarraysum + num <= maxsum) {
                subarraysum += num;
            } else {
                partitions++;
                subarraysum = num;
            }
        }
        return partitions;
    }

    int splitArray(vector<int>& nums, int k) {
        int low = *max_element(nums.begin(), nums.end());
        int high = accumulate(nums.begin(), nums.end(), 0);
        int size = nums.size();

        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (partition(nums, size, mid) <= k) {
                high = mid - 1;   // try smaller
            } else {
                low = mid + 1;    // need bigger
            }
        }
        return low; // smallest max sum that works
    }
};
