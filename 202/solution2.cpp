class Solution {
public:
    int next(int n) {
        int result = 0;
        while(n != 0) {
            int digit = n % 10;
            result += digit * digit;
            n /= 10;
        }
        return result;
    }

    bool isHappy(int n) {
        int slow = n;
        int fast = next(n);
        while(true) {
            if(fast == 1) return true;
            if(fast == slow) return false;

            slow = next(slow);
            fast = next(next(fast));
        }
    }
};