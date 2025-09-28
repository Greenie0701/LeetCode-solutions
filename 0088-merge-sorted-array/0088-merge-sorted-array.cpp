class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        // Check the total size of results array len(num1)+len(num2)-1
        int last  = m+n-1;
        // Iterate through both arrays and move elements to the last based upon comp
        while(m>0 && n>0){
            // If my second array element is greater move to last & decrement n by 1
            if(nums2[n-1]>nums1[m-1]){
                nums1[last] = nums2[n-1];
                n--;
            }
            // Else move first array element to last & decrement m by 1
            else{
                nums1[last] = nums1[m-1];
                m--;
            }
            // Regardless of m and n, after every comp decrement last by 1
            last--;
        }
        // Move remaining elements from array 2
        while(n>0){
            nums1[last]=nums2[n-1];
            n--;
            last--;
        }
    }
};
