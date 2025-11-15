class Solution {
public:
    bool isPowerOfTwo(int n) {
        // When we say a number is a power of 2, then there exist only one set bit in the number
        // How to do that, lets say you have you taken 8 and 7
        // 8 - 1000  take this as n
        // 7 - 0111  take this as n-1 , if the and operation of this to is not 0 then it is a power of 2
        return n > 0 && (n & (n - 1)) == 0;
    }
};