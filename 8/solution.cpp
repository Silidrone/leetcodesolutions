class Solution {
public:
    int myAtoi(string s) {
        int i = 0;

        for(; i < s.size() && isspace(s[i]); i++);

        int sign = 1;
        if(s[i] == '-' || s[i] == '+') {
            if(s[i] == '-') sign = -1;
            i++; 
        }

        for(; i < s.size() && s[i] == '0'; i++);

        const int max_div_10 = std::numeric_limits<int>::max() / 10;
        const int min_div_10 = std::numeric_limits<int>::min() / 10;
        int result = 0;
        for(; i < s.size() && isdigit(s[i]); i++) {
            int digit = (s[i] - '0') * sign;
            if(result > max_div_10 || (result == max_div_10 && digit > 7)) {
                return std::numeric_limits<int>::max();
            } else if(result < min_div_10 || (result == min_div_10 && digit < -8)) {
                return std::numeric_limits<int>::min();
            } else {
                result = result * 10 + digit; 
            }
        }

        return result;
    }
};
