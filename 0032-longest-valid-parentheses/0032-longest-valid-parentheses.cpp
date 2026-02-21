class Solution {
public:
    int longestValidParentheses(string s) {
        int maxi =0;
        int left=0;
        int right =0;

        for(char ch:s){
            if(ch=='('){
                left++;
            }
            else if(ch==')'){
                right++;
            }
            if(left==right){
                maxi = max(maxi, left+right);
            }
            if(left>right&&right!=0){
                maxi = max(maxi, 2*right);
            }
            if(right>left){
                left=0;
                right=0;
            }
        }
        return maxi;
    }
};