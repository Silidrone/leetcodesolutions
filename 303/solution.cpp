class NumArray {
public:
    std::vector<int> prefix_sum;

    NumArray(vector<int>& nums) {
        for(int i = 0; i < nums.size(); i++) {
            prefix_sum.push_back(nums[i]);
            if(i > 0) {
                prefix_sum[i] += prefix_sum[i - 1];
            }
        }
    }
    
    int sumRange(int left, int right) {
        int left_val = 0;
        if(left - 1 >= 0) left_val = prefix_sum[left - 1];
        return prefix_sum[right] - left_val;
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */