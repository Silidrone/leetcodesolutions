#include <vector>

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int length = 0;
        for(int i = 0; i < nums.size(); ++i) {
            int current = nums[i];
            if(length == 0 || nums[length - 1] < current) nums[length++] = current;
            else nums[lwr_bound(nums, 0, length, current)] = current;             
        }

        return length;
    }

    int lwr_bound(vector<int>& arr, int s, int e, int v) {
        while(s < e) {
            int m = s + (e - s) / 2;
            if(arr[m] < v) {
                s = m + 1;
            } else {
                e = m;
            }
        }

        return s;
    }
};
