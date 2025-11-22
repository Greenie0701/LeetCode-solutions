class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        if(cardPoints.size()==k){
            return(accumulate(cardPoints.begin(), cardPoints.end(),0));
        }
        int size = cardPoints.size();
        int sum = 0;
        int maxi = 0;
        int r =size-1;
        for(int i=0; i<k; i++){
            sum+=cardPoints[i];
        }
        maxi = sum;
        int index = k-1;
        for(int i=0; i<k; i++){
            sum-=cardPoints[index-i];
            sum+=cardPoints[r-i];
            maxi = max(maxi, sum);
        }
        return maxi;
    }
};