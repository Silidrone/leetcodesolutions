class Solution {
public:
    std::vector<std::vector<int>> perm(std::deque<int> nums) {
        if(nums.size() == 1) return std::vector<std::vector<int>>{{nums[0]}};

        std::vector<std::vector<int>> result;
        for(int i = 0; i < nums.size(); i++) {
            int n = nums[0]; 
            nums.pop_front();
            
            std::vector<std::vector<int>> subperms = perm(nums);
            for(auto &subperm : subperms) {
                subperm.push_back(n);
            }

            result.insert(result.end(), subperms.begin(), subperms.end());
            nums.push_back(n);
        }

        return result;        
    }

    std::vector<std::vector<int>> permute(std::vector<int> &nums) {
        std::deque<int> dq(nums.begin(), nums.end());
        return perm(dq);
    }
};
