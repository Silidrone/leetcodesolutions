class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int result = 0;
        int prefix_sum = 0;
        std::unordered_map<int, int> sum_fq;
        sum_fq[0] = 1;
        for(int i = 0; i < nums.size(); i++) {
            prefix_sum += nums[i];
            if(sum_fq.find(prefix_sum - k) != sum_fq.end()) {
                result += sum_fq[prefix_sum - k];
            }
            sum_fq[prefix_sum]++;
        }
        return result;
    }
};
