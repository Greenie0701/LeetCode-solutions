class Solution {
public:
    int countPrimes(int n) {
        if (n <= 2) return 0;
        
        vector<bool> prime(n, true);
        prime[0] = prime[1] = false;

        for (int p = 2; p * p < n; p++) {
            if (prime[p]) {
                for (int i = p * p; i < n; i += p) {
                    prime[i] = false;
                }
            }
        }

        return count(prime.begin(), prime.end(), true);
    }
};
