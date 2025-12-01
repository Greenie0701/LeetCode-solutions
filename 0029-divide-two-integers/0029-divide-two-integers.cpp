class Solution {
public:
    int divide(int dividend, int divisor) {
        if(dividend==INT_MIN&&divisor==-1){
            return INT_MAX;
        }

        bool pos = dividend>0==divisor>0;

        long n = labs(dividend);
        long d = labs(divisor);
        long q = 0;

        while(n>=d){
            int count=0;
            while(n>=(d<<(count+1))){
                count++;
            }
            q+=(1L<<count);
            n-=(d<<count);
        } 

        if(!pos)q=-q;

        if(q<INT_MIN)return INT_MIN;
        if(q>INT_MAX)return INT_MAX;

        return q;
    }
};