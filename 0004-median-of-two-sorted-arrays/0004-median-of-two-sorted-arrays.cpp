class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();
        if(n2<n1){
            return findMedianSortedArrays(nums2, nums1);
        }
        int total = n1+n2;
        int half = (total+1)/2;
        int low = 0;
        int high = n1;
        while(low<=high){
            int m1 = low+(high-low)/2;
            int m2 = half-m1;

            int l1 = (m1-1)<0?INT_MIN:nums1[m1-1];
            int l2 = (m2-1)<0?INT_MIN:nums2[m2-1];
            int r1 = m1>=n1?INT_MAX:nums1[m1];
            int r2 = m2>=n2?INT_MAX:nums2[m2];

            if(l1<=r2 && l2<=r1){
                if((total&1)==0){
                    return((max(l1,l2)+min(r1,r2))/2.0);
                }else{
                    return(double(max(l1,l2)));
                }
            }

            else if(l1>r2){
                high = m1-1;
            }
            else if(l2>r1){
                low = m1+1;
            }
        }
        return 0.0;
    }
};