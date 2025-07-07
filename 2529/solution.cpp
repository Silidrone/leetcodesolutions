class Solution {
public:
    int rcount(std::vector<int> &nums, int i, int j, int n = 0, int p = 0) {
        int mid = (i + j) / 2;
        if(i > j) {
            return std::max(n, p);
        }
        
        if(nums[mid] > 0) {
            return rcount(nums, i, mid - 1, n, p + (j - mid) + 1);
        } else if(nums[mid] < 0) {
            return rcount(nums, mid + 1, j, n + (mid - i) + 1, p);
        }

        nums.erase(nums.begin() + mid);
        return rcount(nums, i, j - 1, n, p);
    }

    int maximumCount(vector<int>& nums) {
        return rcount(nums, 0, nums.size() - 1);
    }
};
