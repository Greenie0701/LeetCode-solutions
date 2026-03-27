class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        long long sum = 0;
        int turn = 0;
        sort(happiness.rbegin(), happiness.rend());
        for(int i=0; i<k; i++){
            sum+=max(0, happiness[i]-turn);
            turn++;
        }
        return sum;
    }
};