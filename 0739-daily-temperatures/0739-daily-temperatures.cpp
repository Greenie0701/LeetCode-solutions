class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> result(n, 0);
        vector<int> nge(n, 0);
        stack<int> s;
        for(int i=n-1; i>=0; i--){
            // Stack contains elements
            while(!s.empty()&&temperatures[s.top()]<=temperatures[i]){
                s.pop();
            }
            // Push if stack is in increasing order, else pop it out
            nge[i]=s.empty()?0:s.top();
            s.push(i);
        }
        for(int i=0; i<n; i++){
            result[i]=!nge[i]?0:abs(i-nge[i]);
        }
        return result;
    }
};