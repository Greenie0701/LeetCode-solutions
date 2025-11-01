class Solution {
public:
    int divide(int dividend, int divisor) {
        // Handle overflow case
        if (dividend == INT_MIN && divisor == -1)
            return INT_MAX;

        // Determine sign
        bool positive = (dividend > 0) == (divisor > 0);

        // Convert to long to avoid overflow on abs
        long n = labs((long)dividend);
        long d = labs((long)divisor);

        long quotient = 0;

        while (n >= d) {
            long temp = d, multiple = 1;
            while (n >= (temp << 1)) {
                temp <<= 1;
                multiple <<= 1;
            }
            n -= temp;
            quotient += multiple;
        }

        if (!positive) quotient = -quotient;

        // Clamp within int range
        if (quotient > INT_MAX) return INT_MAX;
        if (quotient < INT_MIN) return INT_MIN;

        return (int)quotient;
    }
};
