class Solution {
public:
    bool isHappy(int n) {
        std::set<int> history;
        while(history.find(n) == history.end()) {
            history.insert(n);
            int fp = 0;
            while(n != 0) {
                int digit = n % 10;
                fp += digit * digit;
                n /= 10;
            }
            if(fp == 1) return true;
            n = fp;
        }

        return false;
    }
};
