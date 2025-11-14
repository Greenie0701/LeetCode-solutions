class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int size = nums.size()-1;
        stack<int> s;
        vector<int> result(size+1, -1);
        for(int i=2*size; i>=0; i--){
            int index = i%(size+1);
            while(!s.empty() && s.top()<=nums[index]){
                s.pop();
            }
            if(!s.empty()&&i<=size){
                result[i] = s.top();
            }
            s.push(nums[index]);
        }
        return result;
    }
};