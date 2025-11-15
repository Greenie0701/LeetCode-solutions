class Solution {
public:
    double pow(double x, long n){
        if(n==0){
            return 1.0;
        }
        if(n==1){
            return x;
        }
        if(n%2==0){
            return pow(x*x,n/2);
        }
        return x*pow(x, n-1);
    }
    double myPow(double x, int num) {
        long n = num;
        if (n < 0) {
            // Calculate the power of -n and take reciprocal
            return (1.0 / pow(x, -1 * n));
        }
        return pow(x, n);
    }
};