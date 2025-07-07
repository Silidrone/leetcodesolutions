class Solution {
public:
    // both l and r are inclusive
    void reverse(std::vector<int> &nums, int l, int r) {
        while(l < r) {
            std::swap(nums[l++], nums[r--]);
        }
    }

    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        if(n <= 1) return;
        k = (k % n);
        if(k == 0) return;
        
        reverse(nums, 0, n - 1);
        reverse(nums, 0, k - 1);
        reverse(nums, k, n - 1);        
    }
};