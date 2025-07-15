class Solution {
public:
    int minMoves(std::vector<int>& nums, int limit) {
        int n = nums.size();
        int pairCount = n / 2;
        std::vector<int> d(2 * limit + 2, 0);

        for (int i = 0; i < pairCount; ++i) {
            int a = nums[i];
            int b = nums[n - 1 - i];
            int low = std::min(a, b) + 1;
            int high = std::max(a, b) + limit;
            int mid = a + b;

            d[low] -= 1;
            d[mid] -= 1;
            d[mid + 1] += 1;
            d[high + 1] += 1;
        }

        int min_moves = n;
        for(int i = 2, delta = n; i < d.size(); i++) {
            delta += d[i];
            min_moves = std::min(min_moves, delta);
        }

        return min_moves;
    }
};
