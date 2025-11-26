class Solution {
public:
    string removeKdigits(string nums, int k) {
        string s;
        for(int i=0; i<nums.size(); i++){
            while(!s.empty()&&k>0&&s.back()-'0'>nums[i]-'0'){
                s.pop_back();
                k--;
            }
            s.push_back(nums[i]);
        }
        while(k!=0){
            s.pop_back();
            k--;
        }
        int start = 0;
        while(s[start]=='0'&&start<s.length())start++;
        return start==s.length()?"0":s.substr(start);
    }
};