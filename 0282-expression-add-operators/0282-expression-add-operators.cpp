class Solution {
public:
    void solve(string num, int target, int index, int curr, int prev, string exp, vector<string>& result) {
        if(index==num.length()){
            if(curr==target){
                result.push_back(exp);
            }
            return;
        }
        for(int i=index; i<num.length(); i++){
            if(i!=index && num[index]=='0'){
                return;
            }
            string currstr = num.substr(index, i-index+1);
            long currnum = stol(currstr);
            if(index==0){
                solve(num, target, i+1, currnum, currnum, exp+currstr, result);
            }else{
               solve(num, target, i+1, curr+currnum, currnum, exp+"+"+currstr, result);
               solve(num, target, i+1, curr-currnum, -currnum, exp+"-"+currstr, result);
               solve(num, target, i+1, curr-prev+prev*currnum, prev*currnum, exp+"*"+currstr, result); 
            }
        }
    }    
    vector<string> addOperators(string num, int target) {
        vector<string> result;
        solve(num, target, 0, 0, 0, "", result);
        return result;
    }
};