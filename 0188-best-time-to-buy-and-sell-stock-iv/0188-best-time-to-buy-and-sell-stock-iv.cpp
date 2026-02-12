class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> ahead(2, vector<int>(k+1, 0));
        vector<vector<int>> curr(2, vector<int>(k+1, 0));
        for(int i=n-1; i>=0; i--){
            for(int canbuy=0; canbuy<=1; canbuy++){
                for(int left=1; left<=k; left++){
                    if(canbuy){
                        curr[canbuy][left]=max(-prices[i]+ahead[0][left], ahead[1][left]);
                    }
                    else{
                        curr[canbuy][left]=max(prices[i]+ahead[1][left-1], ahead[0][left]);
                    }
                }
            }
            ahead = curr;
        }
        return ahead[1][k];
    }
};