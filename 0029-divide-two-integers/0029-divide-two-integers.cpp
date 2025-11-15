class Solution {
public:
    int divide(int dividend, int divisor) {
        // Handling the INT_MAX
        if(dividend==INT_MIN && divisor==-1){
            return INT_MAX;
        }

        long n = labs(dividend);
        long d = labs(divisor);
        long q = 0;

        // CHeck if it is +ve / -ve
        bool pos = (dividend>0)==(divisor>0);

        // Try to represent divisor in terms of power 2
        while(n>=d){
            int count=0; // track how much time a divisor can be represented in terms of 2
            while (n >= (d << (count + 1))) { // Can be 3 * 2^count+1
                count++; // Increment the count
            }
            q+=(1L<<count); // Add the 2^count(1L is must)
            n-=(d<<count); // Remove the added count;
        }
        if(!pos)q=-q; // Check the sign 

        if(q<INT_MIN)return INT_MIN;
        if(q>INT_MAX)return INT_MAX;

        return int(q);
    }
};