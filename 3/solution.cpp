class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.size() <= 1) return s.size();

        std::set<int> chars;
        int l = 0, r = 0, max = 0;
        while(r < s.size()) {
            auto c_it = chars.find(s[r]); 
            if(c_it != chars.end()) {
                max = std::max(max, r - l);
                chars.erase(s[l]);
                l++;
            } else {
                chars.insert(s[r]);
                r++;
            }
        }

        return std::max(max, r - l);
    }
};
