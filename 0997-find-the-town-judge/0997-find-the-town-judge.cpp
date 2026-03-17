class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        if(n==1)return 1;
        vector<int> I_trust(n+1, 0);
        vector<int> others(n+1, 0);
        for(auto t:trust){
            others[t[1]]++;
            I_trust[t[0]]++;
        }
        int judge = -1;
        for(int i=1; i<n+1; i++){
            if(others[i]==n-1&&I_trust[i]==0)return i;
        }
        return judge;
    }
};