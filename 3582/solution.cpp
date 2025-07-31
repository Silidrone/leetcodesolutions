class Solution {
public:
    std::string generateTag(std::string caption) {
        std::string result = "#";
        bool beginningOfWord = false;
        for(int i = 0; i < caption.size() && result.size() < 100; i++) {
            char c = caption[i];
            if(std::isalpha(c)) {
                if(beginningOfWord) {
                    result += std::toupper(c);
                    beginningOfWord = false;
                } else {
                    result += std::tolower(c);
                }
            } else if(std::isspace(c) && result.size() > 1) {
                beginningOfWord = true;
            }
        }

        return result;
    }
};
