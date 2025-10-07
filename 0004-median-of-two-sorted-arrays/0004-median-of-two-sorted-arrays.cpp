class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();
        if (n2 < n1)
            return findMedianSortedArrays(nums2, nums1);

        int low = 0, high = n1;
        int total = n1 + n2;
        int half = (total + 1) / 2;

        while (low <= high) {
            int m1 = (low + high) / 2;
            int m2 = half - m1;

            int l1 = (m1 > 0) ? nums1[m1 - 1] : INT_MIN;
            int l2 = (m2 > 0) ? nums2[m2 - 1] : INT_MIN;
            int r1 = (m1 < n1) ? nums1[m1] : INT_MAX;
            int r2 = (m2 < n2) ? nums2[m2] : INT_MAX;

            if (l1 <= r2 && l2 <= r1) {
                if (total % 2 == 0)
                    return (max(l1, l2) + min(r1, r2)) / 2.0;
                else
                    return double(max(l1, l2));
            } else if (l1 > r2) {
                high = m1 - 1;
            } else {
                low = m1 + 1;
            }
        }
        return 0.0;
    }
};
