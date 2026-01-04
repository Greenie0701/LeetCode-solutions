class Solution {
public:
    bool isPerfectSquare(int num) {
        int low = 0;
        int high = (num/2);
        if(num==1)return 1;
        while(low<=high){
            int mid = low+(high-low)/2;
            long val = mid*mid;
            if(val==num){
                return true;
            }
            else if(val>num){
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }
        return false;
    }
};