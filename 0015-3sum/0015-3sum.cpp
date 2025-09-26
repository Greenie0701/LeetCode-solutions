class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;

        // Step 1: Sort the array
        // Sorting helps us use the two-pointer technique
        // and also makes it easier to skip duplicates.
        sort(nums.begin(), nums.end());

        // Step 2: Iterate through each number in the array as the first element of the triplet
        for (int i = 0; i < nums.size(); i++) {
            // Skip duplicate values for nums[i] (the first element of the triplet).
            // If nums[i] is the same as nums[i-1], then any triplet starting with nums[i]
            // would already have been found in a previous iteration.
            if (i > 0 && nums[i] == nums[i - 1]) continue;

            // Step 3: Use two pointers to find the other two numbers
            int j = i + 1;              // left pointer (just after i)
            int k = nums.size() - 1;    // right pointer (at the end)

            // Step 4: Search while the two pointers don't overlap
            while (j < k) {
                int sum = nums[i] + nums[j] + nums[k];

                if (sum > 0) {
                    // If sum is too large, we need smaller numbers → move k left
                    k--;
                } else if (sum < 0) {
                    // If sum is too small, we need larger numbers → move j right
                    j++;
                } else {
                    // Found a valid triplet that sums to zero
                    result.push_back({nums[i], nums[j], nums[k]});

                    // Step 5: Skip duplicate values for nums[j] and nums[k]
                    // This avoids repeating the same triplet multiple times.
                    while (j < k && nums[j] == nums[j + 1]) j++;
                    while (j < k && nums[k] == nums[k - 1]) k--;

                    // Move both pointers inward to continue searching
                    j++;
                    k--;
                }
            }
        }

        // Step 6: Return the list of all unique triplets
        return result;
    }
};
