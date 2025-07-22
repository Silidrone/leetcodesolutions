class Solution {
public:
    int maximum69Number(int num) {
        int shift_from_right = -1;
        int num_cpy = num;
        for(int i = 0; num_cpy > 0; i++, num_cpy /= 10) {
            if((num_cpy % 10) == 6) {
                shift_from_right = i;    
            }
        }

        return shift_from_right == -1 ? num : (num + 3 * std::pow(10, shift_from_right));
    }
};
