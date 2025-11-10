class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int size = arr.size();
        // Stores the length of the subarray to the right where arr[i] is the NEXT SMALLER ELEMENT (or equal)
        // This is equivalent to: (Index of next smaller element) - i
        vector<int> nse(size); 
        
        // Stores the length of the subarray to the left where arr[i] is the PREVIOUS SMALLER ELEMENT (or equal)
        // This is equivalent to: i - (Index of previous smaller element)
        vector<int> pse(size); 
        
        stack<int> s; // Monotonic stack stores indices
        long long mod = 1e9 + 7; // Use long long for mod to avoid intermediate overflow during multiplication
        
        // --- 1. Calculate NSE (Next Smaller Element) Array ---
        // Iterating from right to left (size-1 to 0)
        for(int i = size - 1; i >= 0; i--) {
            // Keep popping elements from stack that are GREATER THAN OR EQUAL to arr[i].
            // This ensures the stack is strictly increasing in value for indices.
            // We use >= for NSE to handle duplicates: for duplicates, we count the first occurrence
            // as the minimum to avoid overcounting (we use strict < for PSE later).
            while(!s.empty() && arr[s.top()] >= arr[i]) {
                s.pop();
            }
            
            // If stack is empty, it means arr[i] is the smallest element to the right
            // The length is (end of array index + 1) - current index = size - i
            // The index of next smaller element is 'size' (a virtual boundary).
            if (s.empty()) {
                nse[i] = size - i;
            } else {
                // The index of the next smaller element is s.top().
                // The length of the subarray where arr[i] is the minimum to the right is s.top() - i.
                nse[i] = s.top() - i;
            }
            s.push(i); // Push current index onto the stack
        }
        
        // Clear the stack for the next pass
        while(!s.empty()) {
            s.pop();
        }
        
        // --- 2. Calculate PSE (Previous Smaller Element) Array ---
        // Iterating from left to right (0 to size-1)
        for(int i = 0; i < size; i++) {
            // Keep popping elements from stack that are GREATER THAN OR EQUAL to arr[i].
            // We use STRICTLY > here to handle duplicates: if arr[s.top()] == arr[i], we
            // count the previous duplicate as the PSE to avoid overcounting.
            while(!s.empty() && arr[s.top()] > arr[i]) {
                s.pop();
            }
            
            // If stack is empty, it means arr[i] is the smallest element to the left
            // The index of previous smaller element is -1 (a virtual boundary).
            // The length is current index - (-1) = i + 1.
            if (s.empty()) {
                pse[i] = i + 1;
            } else {
                // The index of the previous smaller element is s.top().
                // The length of the subarray where arr[i] is the minimum to the left is i - s.top().
                pse[i] = i - s.top();
            }
            s.push(i); // Push current index onto the stack
        }
        
        // --- 3. Calculate Final Sum ---
        long long total_sum = 0;
        
        for(int i = 0; i < size; i++) {
            // The number of subarrays where arr[i] is the minimum is:
            // (number of valid start points) * (number of valid end points)
            // = pse[i] * nse[i]
            // The contribution of arr[i] is: arr[i] * pse[i] * nse[i]
            
            // We use 1LL to promote the product to long long before the modulo operation
            long long contribution = (arr[i] * 1LL * pse[i]) % mod;
            contribution = (contribution * nse[i]) % mod;

            total_sum = (total_sum + contribution) % mod;
        }
        
        return (int)total_sum;
    }
};