class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0)return false;
        long long rev =0;
        int org =x;
        while(org>0){
            rev = rev*10+(org%10);
            org = org/10;
        }
        return rev==x;
    }
};