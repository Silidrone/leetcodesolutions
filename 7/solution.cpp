#include <vector>

class Solution {
public:
    int reverse(int x) {
        int result = 0;
        for(; x != 0; x /= 10) {
            if(result > INT_MAX / 10 || result < INT_MIN / 10) return 0;
            result = result * 10 + x % 10;
        }
        return result;
    }
};
