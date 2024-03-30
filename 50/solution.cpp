class Solution {
public:
    double myPow(double x, int n) {
        if(n == 0 || x == 1) return 1;
        if(n < 0) x = 1 / x;
        double retval = 1.0f;
        while(n != 0) {
            if((n % 2) != 0) {
                retval *= x;
            }

            x *= x;
            n = n / 2;
        }

        return retval;
    }
};
