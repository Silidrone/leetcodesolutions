class Solution {
public:
    int arrangeCoins(int n) {
        return std::floor((-1 + std::sqrt(1 + 8LL * n)) / 2);
    }
};
