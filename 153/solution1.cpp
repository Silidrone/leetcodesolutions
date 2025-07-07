class Solution {
public:
    int find_pivot(std::vector<int> &nums, int l, int r) {
        if(l >= r) return 0; // no pivot
        int mid = l + (r - l) / 2;
        
        if(mid < r && nums[mid] > nums[mid + 1]) return mid + 1;
        if(mid > l && nums[mid] < nums[mid - 1]) return mid;

        if(nums[l] >= nums[mid]) {
            return find_pivot(nums, l, mid - 1);
        }

        return find_pivot(nums, mid + 1, r);
    }

    int findMin(vector<int>& nums) {
        return std::min(nums[0], nums[find_pivot(nums, 0, nums.size() - 1)]);
    }
};
