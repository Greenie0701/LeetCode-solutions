class Solution {
public:
    long long largestPerimeter(vector<int>& nums) {
        long long perimeter =-1;
        long long sum=0;
        sort(nums.begin(), nums.end());
        for(int& n:nums){
            sum+=n;
            if(sum-n>n){
                perimeter=sum;
            }
        }
        return perimeter;
    }
};