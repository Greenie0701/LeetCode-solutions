class Solution {
public:
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
        int g = garbage.size();
        int t = travel.size();
        vector<int> travel_sum(g);
        travel_sum[0]=0;
        for(int i = 1; i < g; i++){
            travel_sum[i] = travel_sum[i-1] + travel[i-1];
        }
        int m_idx=-1;
        int p_idx=-1;
        int g_idx=-1;
        int m_count=0;
        int p_count=0;
        int g_count=0;
        for(int i=0; i<g; i++){
            for(int j=0; j<garbage[i].length(); j++){
                if(garbage[i][j]=='P'){
                    p_idx=i;
                    p_count++;
                }
                else if(garbage[i][j]=='M'){
                    m_idx=i;
                    m_count++;
                }
                else{
                    g_idx=i;
                    g_count++;
                }
            }
        }
        int result=0;
        if(m_idx!=-1)result+=(travel_sum[m_idx]+m_count);
        if(p_idx!=-1)result+=(travel_sum[p_idx]+p_count);
        if(g_idx!=-1)result+=(travel_sum[g_idx]+g_count);
        return result;
    }
};