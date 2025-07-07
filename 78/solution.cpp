class Solution {
public:
    void comb(std::vector<int> &nums, std::vector<std::vector<int>>& result, int i) {
        std::vector<int> cv = {nums[i]};
        if(i != nums.size() - 1) {
            comb(nums, result, i + 1);
            int result_size = result.size();
            for(int j = 0; j < result_size; j++) {
                std::vector<int> nv = cv;
                nv.insert(nv.end(), result[j].begin(), result[j].end());
                result.push_back(nv);
            }
        }
        result.push_back(cv);
    }

    std::vector<std::vector<int>> subsets(std::vector<int>& nums) {
        std::vector<std::vector<int>> result;
        comb(nums, result, 0);
        result.push_back(std::vector<int>());
        return result;
    }
};
