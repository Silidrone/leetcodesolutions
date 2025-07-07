class Solution {
protected:
    std::unordered_map<int, int> results_memo;
public:
    int climbStairs(int n) {
        if(n < 0) return 0;
        if(n == 0) return 1;
        auto it = results_memo.find(n);
        if(it != results_memo.end()) return it->second;
        int result = climbStairs(n - 1) + climbStairs(n - 2);
        results_memo[n] = result;
        return result;
    }
};
