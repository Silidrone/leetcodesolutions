class Solution {
public:
    string convert(string s, int numRows) {
        int str_len = s.size();
        if(numRows > str_len || numRows == 1 || str_len == 1) return s;
        std::string result;
        std::vector<int> offsets;
        for(int i = 2 * numRows - 2; i > 0; i -= 2) {
            offsets.push_back(i);
        }
        offsets.push_back(2 * numRows - 2);
        
        for(int i = 0; i < numRows; i++) {
            bool zigzag_flag = false;
            int indx = i;
            do {
                result += s[indx];
                int offset = zigzag_flag ? (offsets[numRows - (i + 1)]) : offsets[i];
                indx += offset;
                zigzag_flag = !zigzag_flag;
            } while(indx < str_len);
        }

        return result;
    }
};
