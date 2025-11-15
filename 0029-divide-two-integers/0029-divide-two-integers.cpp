class Solution {
public:
    int divide(int dividend, int divisor) {
        if (dividend == INT_MIN && divisor == -1)
            return INT_MAX;

        bool positive = (dividend > 0) == (divisor > 0);

        long n = labs((long)dividend);
        long d = labs((long)divisor);

        long quotient = 0;

        while (n >= d) {
            int count = 0;
            while (n >= (d << (count + 1))) {
                count++;
            }
            n -= d << count;
            quotient += 1L << count;
        }

        if (!positive) quotient = -quotient;

        if (quotient > INT_MAX) return INT_MAX;
        if (quotient < INT_MIN) return INT_MIN;

        return (int)quotient;
    }
};
