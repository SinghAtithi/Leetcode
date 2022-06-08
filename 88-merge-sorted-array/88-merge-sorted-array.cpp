class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i=m,j=n;
        for(int k=0;k<n;k++){
            nums1[i]=nums2[k];
            i++;
        }
        sort(nums1.begin(),nums1.end());
    }
};