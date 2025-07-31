class Solution {
public:
    bool isVowel(char c) {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }

    bool isVowelString(std::string &s) {
        return isVowel(s[0]) && isVowel(s[s.size() - 1]);
    }

    int vowelStrings(std::vector<std::string>& words, int left, int right) {
        int result = 0;
        for(int i = left; i <= right; i++) {
            if(isVowelString(words[i])) result++;
        }

        return result;
    }
};
