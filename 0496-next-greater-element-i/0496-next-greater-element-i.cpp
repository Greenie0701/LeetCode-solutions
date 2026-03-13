class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> s;
        unordered_map<int, int> m;
        for(int i=nums2.size()-1; i>=0; i--){
            while(!s.empty()&&s.top()<=nums2[i]){
                s.pop();
            }
            m[nums2[i]]=s.empty()?-1:s.top();
            s.push(nums2[i]);
        }
        vector<int> result;
        for(int n:nums1){
            result.push_back(m[n]);
        }
        return result;
    }
};