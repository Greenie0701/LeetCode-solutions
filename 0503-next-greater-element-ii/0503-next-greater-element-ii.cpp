class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        stack<int> s;
        int size=nums.size()-1;
        vector<int> nge(size+1);
        for(int i=2*size; i>=0; i--){
            int index = i%(size+1);
            while(!s.empty() && s.top()<=nums[index]){
                s.pop();
            }
            if(i<=size){
                int element = s.empty()?-1:s.top();
                nge[i]=element;
            }
            s.push(nums[index]);
        }
        return nge;
    }
};