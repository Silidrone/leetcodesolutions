#include <algorithm>

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        std::unordered_map<int, int> val_idx_map;

        for(int i = 0; i < nums1.size(); i++) {
            val_idx_map[nums1[i]] = i;
        }

        std::vector<int> result(nums1.size(), -1);
        std::stack<int> monotonic_stack;
        for(int i = 0; i < nums2.size(); i++) {
            int n = nums2[i];
            while(!monotonic_stack.empty() && n > monotonic_stack.top()) {
                result[val_idx_map[monotonic_stack.top()]] = n;
                monotonic_stack.pop();
            }
            auto it = val_idx_map.find(n);
            if(it != val_idx_map.end()) {
                monotonic_stack.push(n);
            }
        }

        return result;
    }
};
