class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        long long sum = 0;
        int turn = 0;
        priority_queue<int> pq;
        for(int& n:happiness){
            pq.push(n);
        }
        for(int i=0; i<k; i++){
            sum+=max(pq.top()-turn, 0);
            pq.pop();
            turn++;
        }
        return sum;
    }
};