class Solution {
public:
    string repeatLimitedString(string s, int repeatLimit) {
        priority_queue<pair<int, int>> pq;
        vector<int> freq(26, 0);
        for(char& ch:s){
            freq[ch-'a']++;
        }
        for(int i=0; i<26; i++){
            if(freq[i])pq.push({i, freq[i]});
        }
        string result="";
        while(!pq.empty()){
            auto val = pq.top();
            pq.pop();
            if(!result.empty()&&result.back()==(val.first+'a')){
                if(pq.empty())break;
                auto val2 = pq.top();
                pq.pop();
                result.append(1, val2.first+'a');
                if(val2.second!=1)pq.push({val2.first, val2.second-1});
                pq.push(val);
            }
            else{
                result.append(min(repeatLimit, val.second), val.first+'a');
                if(val.second>repeatLimit)pq.push({val.first, val.second-repeatLimit});
            }
        }
        return result;
    }
};