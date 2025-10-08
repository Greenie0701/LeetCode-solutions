class Solution {
public:
    bool possible(vector<int>& piles, int k, int h){
        int size = piles.size();
        long long hours = 0;
        for(int i = 0; i<size; i++){
            hours+=ceil(double(piles[i])/double(k));
        }
        if(hours<=h){
            return true;
        }
        else{
            return false;
        }
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        // Initialise the search space
        int low = 1;
        int high = *max_element(piles.begin(), piles.end());
        int ans = -1;
        // Perform binary search to 
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