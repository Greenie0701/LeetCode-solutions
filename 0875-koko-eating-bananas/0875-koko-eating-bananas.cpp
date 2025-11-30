class Solution {
public:
    bool possible(vector<int>& piles, int speed, int h){
        long long hour = 0;
        for(int i=0; i<piles.size(); i++){
            hour+=ceil(double(piles[i])/double(speed));
        }
        if(hour<=h){
            return true;
        }
        return false;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1;
        int high = *max_element(piles.begin(), piles.end());
        int ans =-1;
        while(low<=high){
            int mid = low+(high-low)/2;

            if(possible(piles, mid, h)){
                ans = mid;
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }
        return ans;
    }
};