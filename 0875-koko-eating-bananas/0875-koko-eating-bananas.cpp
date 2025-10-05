class Solution {
public:
    bool possible(vector<int>& piles, int size, int speed, int h){
        long long k = 0;
        for(int i=0; i<size; i++){
            k+=ceil(double(piles[i])/double(speed));
        }
        if(k<=h){
            return true;
        }else{
            return false;
        }
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        // Initialise the range for the search
        int low = 1;
        int high = *max_element(piles.begin(), piles.end());
        int size = piles.size();
        int min_speed = INT_MAX;
        // Search through the entire range for minimal speed
        while(low<=high){
            int mid = low+(high-low)/2;
            if(possible(piles, size, mid, h)){
                min_speed=min(mid, min_speed);
                high =  mid-1;
            }else{
                low = mid+1;
            }
        }
        return low;
    }
};