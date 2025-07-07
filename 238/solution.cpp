class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        std::vector<int> lr_products(nums.size(), 1);
        for(int i = 1; i < nums.size(); i++)
            lr_products[i] = nums[i - 1] * lr_products[i - 1];
        
        for(int i = nums.size() - 2, right = 1; i >= 0; i--) {
            right *= nums[i + 1];
            lr_products[i] *= right;
        }
        
        return lr_products;
    }
};
