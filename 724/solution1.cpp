class Solution {
public:
    int pivotIndex(std::vector<int>& nums) {
        if(nums.size() == 1) return 0;

        std::vector<int> sum_right(nums.size(), 0);

        sum_right[nums.size() - 1] = nums[nums.size() - 1];
        for(int i = nums.size() - 1; i > 0; i--) {
            sum_right[i - 1] += nums[i - 1] + sum_right[i];
        }

        for(int i = 0, sum_left = 0; i < nums.size(); i++) {
            sum_left += nums[i];
            if(sum_left == sum_right[i]) return i;
        }

        return -1;
    }
};
