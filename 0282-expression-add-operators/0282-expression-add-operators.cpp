class Solution {
public:
    void createexp(string num, int target, vector<string>& result, int index, long curr, long prev, string exp){
        if(index==num.size()){
            if(curr==target){
                result.push_back(exp);
            } 
            return;
        }
        for(int i=index; i<num.size(); i++){
            if(i!=index && num[index]=='0')return;

            string currstr = num.substr(index, i-index+1);
            long currnum = stol(currstr);

            if(index==0){
                createexp(num, target, result, i+1, currnum, currnum, exp+currstr);
            }else{
                createexp(num, target, result, i+1, curr+currnum, currnum, exp+"+"+currstr);
                createexp(num, target, result, i+1, curr-currnum, -currnum, exp+"-"+currstr);
                createexp(num, target, result, i+1, curr-prev+prev*currnum, prev*currnum, exp+"*"+currstr);
            }
        }
    }
    vector<string> addOperators(string num, int target) {
        vector<string> result;
        createexp(num, target, result, 0, 0, 0, "");
        return result;
    }
};