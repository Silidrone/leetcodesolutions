#include <unordered_map>

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> vals;

        for(int i = 0; i < nums.size(); i++) {
            auto solution = vals.find(target - nums[i]);
            if(solution != vals.end()) {
                return std::vector<int>({i, solution->second});
            }

            vals[nums[i]] = i;
        }

        return std::vector<int>();
    }
};
