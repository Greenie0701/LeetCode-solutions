class Solution {
public:
    // int dfs(int amount, int i, vector<int>& coins){
    //     if(amount==0)return 1;
    //     if(i==0){
    //         if(amount%coins[0]==0)return 1;
    //         return 0;
    //     }
    //     if(i<0)return 0;
    //     // Either two ways - dont pick the current coin else pick the next coin
    //     int not_pick = dfs(amount, i-1, coins);
    //     int pick = 0;
    //     if(coins[i]<=amount){
    //         pick = dfs(amount-coins[i], i, coins);
    //     }
    //     return not_pick+pick;
    // }
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<unsigned long long> prev(amount+1, 0);
        prev[0]=1;
        for(int i=1;i<amount+1; i++){
            if(i%coins[0]==0)prev[i]=1;
        }
        // return dfs(amount, n-1, coins);
        for(int i = 1; i < n; i++){
            vector<unsigned long long> curr(amount + 1, 0);
            curr[0] = 1;

            for(int t = 1; t <= amount; t++){
                unsigned long long not_pick = prev[t];
                unsigned long long pick = 0;
                if(coins[i] <= t){
                    pick = curr[t - coins[i]];
                }
                curr[t] = pick + not_pick;
            }
            prev = curr;
        }

        return prev[amount];
    }
};