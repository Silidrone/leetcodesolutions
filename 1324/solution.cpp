class Solution {
public:
    inline void rtrim(std::string &s) {
        s.erase(std::find_if(s.rbegin(), s.rend(), [](unsigned char ch) {
            return !std::isspace(ch);
        }).base(), s.end());
    }

    std::vector<std::string> printVertically(std::string s) {
        int longest_word_length = 0, word_count = 1, word_length = 0;
        std::vector<std::string> result(200, std::string(200, ' '));
        for(int i = 0; i < s.size(); i++) {
            if(s[i] == ' ') {
                longest_word_length = std::max(longest_word_length, word_length);
                word_count++;
                word_length = 0;
            } else {
                result[word_length++][word_count - 1] = s[i];
            }
        }
        
        longest_word_length = std::max(longest_word_length, word_length);
        
        result.resize(longest_word_length);
        
        for(auto& s : result) {
            rtrim(s);
        }

        return result;
    }
};

