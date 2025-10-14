class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size()==1){
            return 0;
        }
        int mini_buy = prices[0];
        int profit = 0;
        for(int i=1;i<prices.size();i++){
            int current_profit = prices[i]-mini_buy;
            profit = max(profit, current_profit);
            mini_buy = min(mini_buy, prices[i]);
        }
        return profit;
    }
};