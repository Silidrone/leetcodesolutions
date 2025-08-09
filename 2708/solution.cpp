class Solution {
public:
    long long maxStrength(std::vector<int>& nums) {
        if(nums.size() == 1) return nums[0];

        std::sort(nums.begin(), nums.end());
        long long product = 1;
        int negative_count = 0, positive_count = 0;
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] > 0) positive_count++;
            if(nums[i] < 0) negative_count++;

            if(product * nums[i] < 0 && ((i == nums.size() - 1) || nums[i + 1] >= 0))
            {
                negative_count--;
                continue;
            } 
            
            if (nums[i] != 0) {
                product *= nums[i];
            }
        }

        if(positive_count == 0 && negative_count == 0) {
            return 0;
        }

        return product;
    }
};
