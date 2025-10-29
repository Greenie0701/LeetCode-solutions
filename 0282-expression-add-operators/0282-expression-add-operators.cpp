class Solution {
public:
    void expaddops(string num, int target, int index, long curr, long prev, string exp, vector<string>& result) {
        // Base Case
        if (index == num.length()) {
            if (curr == target)
                result.push_back(exp);
            return;
        }

        // Try all partitions
        for (int i = index; i < num.length(); i++) {
            // Skip leading zeros
            if (i != index && num[index] == '0') break;

            string currnumstr = num.substr(index, i - index + 1);
            long currnum = stol(currnumstr);

            if (index == 0) {
                // First number, no operator before it
                expaddops(num, target, i + 1, currnum, currnum, currnumstr, result);
            } else {
                expaddops(num, target, i + 1, curr + currnum, currnum, exp + "+" + currnumstr, result);
                expaddops(num, target, i + 1, curr - currnum, -currnum, exp + "-" + currnumstr, result);
                expaddops(num, target, i + 1, curr - prev + prev * currnum, prev * currnum, exp + "*" + currnumstr, result);
            }
        }
    }

    vector<string> addOperators(string num, int target) {
        vector<string> result;
        expaddops(num, target, 0, 0, 0, "", result);
        return result;
    }
};
