class Solution {
public:
    bool possible(vector<int>& piles, int k, int h){
        int n = piles.size();
        long long total = 0;
        for(int i=0; i<n; i++){
            total+=ceil(double(piles[i])/double(k));
        }
        if(total<=h){
            return true;
        }else{
            return false;
        }
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1;
        int high = *max_element(piles.begin(), piles.end());
        int ans = -1;
        while(low<=high){
            int mid = low+(high-low)/2;
            if(possible(piles, mid, h)){
                ans = mid;
                high = mid-1;
            }else{
                low = mid+1;
            }
        }
        return ans;
    }
};