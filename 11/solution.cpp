class Solution {
public:
    int maxArea(vector<int>& height) {
        int l = 0, r = height.size() - 1;
        int result = -1;
        while(l < r) {
            if(height[l] <= height[r]) {
                result = std::max(result, height[l] * (r - l));
                l++;
            } else {
                result = std::max(result, height[r] * (r - l));
                r--;
            }
        }

        return result;
    }
};
