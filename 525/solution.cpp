class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        std::unordered_map<int, int> hm;
        
        hm[0] = -1;

        int prefix_sum = 0;
        int max_len = 0;
        for(int i = 0; i < nums.size(); i++) {
            prefix_sum += (nums[i] == 0) ? -1 : 1;

            auto it = hm.find(prefix_sum);
            if(it != hm.end()) {
                int curr_len = i - hm[prefix_sum];
                if(curr_len > max_len) max_len = curr_len;
            } else {
                hm[prefix_sum] = i;
            }
        }
        return max_len;
    }
};