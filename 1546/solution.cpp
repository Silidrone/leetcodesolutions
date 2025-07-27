class Solution {
public:
    int maxNonOverlapping(std::vector<int>& nums, int target) {
        std::unordered_map<int, int> prefix_sum{{0, -1}};
        int result = 0;
        for(int i = 0, sum = 0, last = -1; i < nums.size(); i++) {
            sum += nums[i];
            if(prefix_sum.count(sum - target) && last <= prefix_sum[sum - target]) {
                last = i;
                result++;
            }
            prefix_sum[sum] = i;
        }
        return result; 
    }
};
