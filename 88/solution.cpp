class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m - 1;
        int j = n - 1;
        int k = (m + n) - 1; // the index at which we will start inserting the merge sorted elements

        while(i >= 0 && j >= 0) {
            if(nums1[i] <= nums2[j]) {
                nums1[k] = nums2[j];
                j--;
            } else {
                nums1[k] = nums1[i];
                i--;
            }

            k--;
        }

        for(; j >= 0; j--, k--) {
            nums1[k] = nums2[j];
        }
    }
};
