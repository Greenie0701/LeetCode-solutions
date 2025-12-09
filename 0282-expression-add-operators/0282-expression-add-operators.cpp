class Solution {
public:
    void find(string num, int target, vector<string>& result, long curr, long prev, int index,string exp){
        if(index==num.length()){
            if(curr==target){
                result.push_back(exp);
            }
            return;
        }
        for(int i=index; i<num.length(); i++){
            if(i!=index && num[index]=='0')return;
            string currstr = num.substr(index, i-index+1);
            long currnum = stol(currstr);
            if(index==0){
                find(num, target, result, currnum, currnum, i+1, exp+currstr);
            }else{
                find(num, target, result, curr+currnum, currnum, i+1, exp+'+'+currstr);
                find(num, target, result, curr-currnum, -currnum, i+1, exp+'-'+currstr);
                find(num, target, result, curr-prev+prev*currnum, prev*currnum, i+1, exp+'*'+currstr);
            }
        }
    }
    vector<string> addOperators(string num, int target) {
        vector<string> result;
        find(num, target, result, 0, 0, 0, "");
        return result;
    }
};