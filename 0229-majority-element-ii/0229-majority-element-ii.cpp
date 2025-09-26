class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        
        // Step 1: Find two candidates
        int c1 = 0, c2 = 0;          // counters
        int el1 = INT_MIN, el2 = INT_MIN; // potential candidates

        for (int num : nums) {
            if (num == el1) {
                c1++;  // increment count for candidate 1
            }
            else if (num == el2) {
                c2++;  // increment count for candidate 2
            }
            else if (c1 == 0) {
                el1 = num;  // assign new candidate 1
                c1 = 1;
            }
            else if (c2 == 0) {
                el2 = num;  // assign new candidate 2
                c2 = 1;
            }
            else {
                // current number not matching either candidate
                // reduce votes from both
                c1--;
                c2--;
            }
        }

        // Step 2: Verify candidates
        c1 = 0; 
        c2 = 0;
        for (int num : nums) {
            if (num == el1) c1++;
            else if (num == el2) c2++;
        }

        // Step 3: Collect results
        vector<int> result;
        if (c1 > n/3) result.push_back(el1);
        if (c2 > n/3) result.push_back(el2);

        return result;
    }
};
