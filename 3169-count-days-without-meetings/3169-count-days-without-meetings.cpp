class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        sort(meetings.begin(), meetings.end());
        int count = 0;
        if(meetings[0][0]>1)count+=(meetings[0][0]-1);
        int current_end=meetings[0][1];
        for(int i=1; i<meetings.size(); i++){
            if(current_end>=meetings[i][0]){
                current_end = max(current_end, meetings[i][1]);
                continue;
            }
            else{
                count+=(meetings[i][0]-current_end-1);
                current_end = meetings[i][1];
            }
        }
        if(current_end<days)count+=(days-current_end);
        return count;
    }
};