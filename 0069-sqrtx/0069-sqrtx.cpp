class Solution {
public:
    int mySqrt(int x) {
        if(x<2)return x;
        /*
        16 - 0 8 , 4


        */
        long long low = 0;
        long long high = x/2;
        long long ans=-1;
        while(low<=high){
            long long mid = low+(high-low)/2;
            long long val = mid*mid;
            if(val>x){
                high = mid-1;
            }
            else if(val==x){
                return int(mid);
            }
            else{
                ans = mid;
                low = mid+1;
            }
        }
        return int(ans);
    }
};