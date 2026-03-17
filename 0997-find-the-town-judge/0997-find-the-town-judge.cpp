class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        if(n==1)return 1;
        // vector<int> I_trust(n+1, 0);
        // vector<int> others(n+1, 0);
        vector<int> scores(n+1, 0);;
        for(auto t:trust){
            scores[t[1]]++;
            scores[t[0]]--;
        }
        for(int i=1; i<n+1; i++){
            if(scores[i]==n-1)return i;
        }
        return -1;
    }
};