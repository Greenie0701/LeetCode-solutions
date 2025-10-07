class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if (nums2.size() < nums1.size()) {
            return findMedianSortedArrays(nums2, nums1);
        }

        int n1 = nums1.size();
        int n2 = nums2.size();
        int low = 0, high = n1;

        while (low <= high) {
            int m1 = low + (high - low) / 2;
            int m2 = (n1 + n2 + 1) / 2 - m1;

            int l1 = (m1 == 0) ? INT_MIN : nums1[m1 - 1];
            int r1 = (m1 == n1) ? INT_MAX : nums1[m1];
            int l2 = (m2 == 0) ? INT_MIN : nums2[m2 - 1];
            int r2 = (m2 == n2) ? INT_MAX : nums2[m2];

            if (l1 <= r2 && l2 <= r1) {
                // Correct partition found
                if ((n1 + n2) % 2 == 0) {
                    return (max(l1, l2) + min(r1, r2)) / 2.0;
                } else {
                    return double(max(l1, l2));
                }
            } else if (l1 > r2) {
                // Move left
                high = m1 - 1;
            } else {
                // Move right
                low = m1 + 1;
            }
        }

        // Should never reach here if input arrays are valid
        return 0.0;
    }
};
