class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int min_size = nums.size() + 1;
        for(int r = 0, l = 0, sum = 0; r < nums.size(); r++) {
            sum += nums[r];

            while(sum >= target) {
                min_size = std::min(min_size, r - l + 1);
                sum -= nums[l];
                l++;
            }
        }

        return min_size == nums.size() + 1 ? 0 : min_size;
    }
};
