class Solution {
public:
    vector<int> runningSum(vector<int> &nums) {
        if(nums.empty()) return {};

        vector<int> sums;
        sums.push_back(nums[0]);
        for(int i = 1; i < nums.size(); i++) {
            sums.push_back(nums[i] + sums[i - 1]);
        }

        return sums;
    }
};
