class Solution {
public:
    int pivotIndex(std::vector<int>& nums) {
        if(nums.size() == 1) return 0;

        int total_sum = 0;
        for(int i = 0; i < nums.size(); i++) {
            total_sum += nums[i];
        }

        for(int i = 0, sum_left = 0; i < nums.size(); i++) {
            if(sum_left == total_sum - nums[i] - sum_left) {
                return i;
            }

            sum_left += nums[i];
        }

        return -1;
    }
};