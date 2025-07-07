class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if (s.length() != t.length()) {
            return false;
        }

        unordered_map<char, char> map1;
        unordered_map<char, char> map2;

        for(int i = 0; i < s.length(); i++) {
            char c1 = s[i];
            char c2 = t[i];

            if(map1.find(c1) == map1.end()) {
                map1[c1] = c2;
            } else if (map1[c1] != c2) {
                return false;
            }

            if(map2.find(c2) == map2.end()) {
                map2[c2] = c1;
            } else if(map2[c2] != c1) {
                return false;
            }
        }

        return true;
    }
};
