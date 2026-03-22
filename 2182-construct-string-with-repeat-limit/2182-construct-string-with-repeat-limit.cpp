class Solution {
public:
    string repeatLimitedString(string s, int repeatLimit) {
        string result = "";
        vector<int> freq(26, 0);
        for(char& c:s){
            freq[c-'a']++;
        }
        priority_queue<pair<int, int>> pq;
        for(int i=0; i<26; i++){
            if(!freq[i])continue;
            pq.push({i, freq[i]});
        }
        while(!pq.empty()){
            auto val = pq.top();
            pq.pop();
            if(!result.empty() && val.first+'a'==result.back()){
                if(pq.empty())break;
                auto val2 = pq.top();
                pq.pop();
                result.append(1, val2.first+'a');
                pq.push(val);
                if(val2.second==1)continue;
                pq.push({val2.first, val2.second-1});
            }
            else{
                int f = min(val.second, repeatLimit);
                result.append(f, (val.first+'a'));
                if(repeatLimit<val.second)pq.push({val.first, val.second-repeatLimit});
            }
        }
        return result;
    }
};

// a - 4
// b - 3

// 2
// [1, 1]
// [0, 4]

// "bb"


