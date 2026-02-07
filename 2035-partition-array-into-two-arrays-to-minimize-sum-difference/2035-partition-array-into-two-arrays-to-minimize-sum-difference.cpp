class Solution {
public:
    int minimumDifference(vector<int>& nums) {
        int n = nums.size();
        int N = n / 2;
        int total = accumulate(nums.begin(), nums.end(), 0);

        vector<vector<int>> left(N + 1), right(N + 1);

        // Generate subset sums
        for (int mask = 0; mask < (1 << N); mask++) {
            int cnt = 0, lsum = 0, rsum = 0;

            for (int i = 0; i < N; i++) {
                if (mask & (1 << i)) {
                    cnt++;
                    lsum += nums[i];
                    rsum += nums[i + N];
                }
            }

            left[cnt].push_back(lsum);
            right[cnt].push_back(rsum);
        }

        // Sort right half for binary search
        for (int i = 0; i <= N; i++)
            sort(right[i].begin(), right[i].end());

        int ans = INT_MAX;

        // Try all ways of picking k from left
        for (int k = 0; k <= N; k++) {
            for (int a : left[k]) {

                int need = total / 2 - a;  // target for right
                auto &vec = right[N - k];

                auto it = lower_bound(vec.begin(), vec.end(), need);

                // Check lower_bound
                if (it != vec.end()) {
                    int sumChosen = a + *it;
                    ans = min(ans, abs(total - 2 * sumChosen));
                }

                // Check previous element
                if (it != vec.begin()) {
                    --it;
                    int sumChosen = a + *it;
                    ans = min(ans, abs(total - 2 * sumChosen));
                }
            }
        }

        return ans;
    }
};
