class Solution {
public:
    std::vector<std::vector<int>> threeSum(std::vector<int>& nums) {
        std::sort(nums.begin(), nums.end());

        std::vector<std::vector<int>> triplets;
        for(int i = 0; i < nums.size(); i++) {
            if(i > 0 && nums[i] == nums[i - 1]) continue;

            int l = i + 1, r = nums.size() - 1, target = -nums[i];
            while(l < r) {
                int pair_sum = nums[l] + nums[r];
                if(pair_sum == target) {
                    triplets.push_back(std::vector<int>{nums[i], nums[l], nums[r]});
                    for(l++; l < r && nums[l] == nums[l - 1]; l++);
                } else if(pair_sum < target) {
                    l++;
                } else {
                    r--;
                }
            }
        }

        return triplets;
    }
};