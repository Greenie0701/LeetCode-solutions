class Solution {
public:
    int divide(int dividend, int divisor) {
        if(dividend==INT_MIN&&divisor==-1){
            return INT_MAX;
        }
        // Determine the sign of the number
        bool pos_sign = dividend>0==divisor>0;

        // take copy of the given divisor and dividend
        long n = labs(dividend);
        long d = labs(divisor);
        long q =0;

        // Loop untill you can represent the given divisor in terms of power 2 to get near to the dividend
        while(n>=d){
            int count = 0;
            while(n>=(d<<(count+1))){
                count++;
            }
            n-=(d<<count);
            q+=(1L<<count);
        }

        if(!pos_sign)q=-q;

        if(q>INT_MAX)return INT_MAX;
        if(q<INT_MIN)return INT_MIN;
        
        return q;
    }
};