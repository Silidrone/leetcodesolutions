// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int sol(int s, int e) {
        if(e - s == 0) return 1;

        if(e - s == 1) {
            if(isBadVersion(s)) {
                return s;
            }

            return e;
        }

        int m = s + (e - s) / 2;

        if(isBadVersion(m)) {
            if(isBadVersion(m - 1)) {
                return sol(s, m - 1);
            } else {
                return m;
            }
        } else {
            return sol(m, e);
        }
    }

    int firstBadVersion(int n) {    
        return sol(1, n);
    }
};
