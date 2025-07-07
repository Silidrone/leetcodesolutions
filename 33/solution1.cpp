class Solution {
public:
    int find_pivot(std::vector<int>& nums, int l, int r) {
        if(l >= r) return -1;

        int mid = l + (r - l) / 2;

        if (mid < r && nums[mid] > nums[mid + 1]) return mid + 1;
        if (mid > l && nums[mid] < nums[mid - 1]) return mid;

        if (nums[l] >= nums[mid]) {
            return find_pivot(nums, l, mid - 1);
        }

        return find_pivot(nums, mid + 1, r);
    }

    
    int binary_search(std::vector<int>& nums, int target, int l, int r) {
        if(l > r) return -1;
        int mid = l + (r - l) / 2;

        if(target == nums[mid]) return mid;

        if (target < nums[mid]) {
            return binary_search(nums, target, l, mid - 1);
        }

        return binary_search(nums, target, mid + 1, r);
    }


    int search(std::vector<int>& nums, int target) {
        int n = nums.size();
        int pivot = find_pivot(nums, 0, n - 1);

        if (pivot == -1) {
            return binary_search(nums, target, 0, n - 1);
        }

        int result = binary_search(nums, target, 0, pivot - 1);
        if (result != -1) {
            return result;
        }

        return binary_search(nums, target, pivot, n - 1);
    }
};
