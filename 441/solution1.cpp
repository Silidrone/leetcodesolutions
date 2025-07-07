class Solution {
public:
    int arrangeCoins(int n) {
        long start = 1, end = n;
        while (start <= end) {
            long mid = start + (end - start) / 2;
            long coins = mid * (mid + 1) / 2;
            if (coins == n) return mid;
            if (coins < n) start = mid + 1;
            else end = mid - 1;
        }
        return end;
    }
};
