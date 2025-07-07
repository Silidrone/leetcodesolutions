class Solution {
public:
    int bs(std::vector<int>& arr, int v, int l) {
        int r = arr.size();
        while(l < r) {
            int m = l + (r - l) / 2;
            if(v <= arr[m]) l = m + 1;
            else if(v > arr[m]) r = m;
        }
        
        return l - 1;
    }

    int maxDistance(std::vector<int>& nums1, std::vector<int>& nums2) {
        int max_distance = INT_MIN;
        for(int i = 0; i < nums1.size(); i++) {
            int idx = bs(nums2, nums1[i], i);
            if(idx >= i && idx - i > max_distance) max_distance = idx - i;
        }
        
        return max_distance == INT_MIN ? 0 : max_distance;
    }
};
