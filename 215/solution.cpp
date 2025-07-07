#include <queue>

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        std::priority_queue<int, std::vector<int>, std::greater<int>> min_heap;
        
        int i;
        for(i = 0; i < k; ++i) {
            min_heap.push(nums[i]);
        }
        
        for(; i < nums.size(); ++i) {
            if(min_heap.top() < nums[i]) {
                min_heap.pop();
                min_heap.push(nums[i]);
            }
        }
        
        return min_heap.top();
    }
};
