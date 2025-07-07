#include <numeric>


class Solution {
public:
    int trap(vector<int>& height) {
        if(height.size() <= 2) return 0;

        int result = 0;
        int li = 0;
        int ri = height.size() - 1;
        int lm = height[li];
        int rm = height[ri];
        while(li < ri) {
            if(lm <= rm) {
                li++;
                result += std::max(0, lm - height[li]);
                if(height[li] > lm) lm = height[li];
            } else {
                ri--;
                result += std::max(0, rm - height[ri]);
                if(height[ri] > rm) rm = height[ri];                
            }
        }

        return result;
    }
};