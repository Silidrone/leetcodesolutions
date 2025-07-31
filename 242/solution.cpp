class Solution {
public:
    bool isAnagram(string s, string t) {
        int n = s.size();
        if(n != t.size()) return false;

        std::unordered_map<char, int> freq;
        for(auto &c : s) {
            freq[c]++;
        }

        for(auto &c : t) {
            if(--freq[c] < 0) {
                return false;
            }
        }

        return true;
    }
};
