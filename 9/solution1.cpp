class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0) return false;
        
        std::vector<int> l;
        std::stack<int> s;

        for(int n = x; n != 0; n /= 10) {
            l.push_back(n % 10);
            s.push(n % 10);
        }

        for(int i = 0; i < l.size() && !s.empty(); i++, s.pop()) {
            if(l.size() - 1 - i != 1 && l[i] != s.top()) return false;
        }

        return true;
    }
};
