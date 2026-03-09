class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxi = 0;
        int mini_buy = prices[0];
        for(int i=1; i<prices.size(); i++){
            int curr_profit = prices[i]-mini_buy;
            maxi = max(curr_profit, maxi);
            mini_buy = min(prices[i], mini_buy);
        }
        return maxi;
    }
};