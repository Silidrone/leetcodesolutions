class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        std::unordered_map<int, int> even_fm;
        std::unordered_map<int, int> odd_fm;

        for(int i = 0, j = 1; i < nums.size(); i += 2, j += 2) {
            if(i < nums.size()) {
                even_fm[nums[i]]++;
            }

            if(j < nums.size()) {
                odd_fm[nums[j]]++;
            }
        }

        int even_n = (nums.size() + 1) / 2, odd_n = nums.size() / 2, max1_even_freq = 0, max1_even_val = 0, max2_even = 0, max1_odd_freq = 0, max1_odd_val = 0, max2_odd = 0;

        for(auto [num, freq] : even_fm) {
            if(freq > max1_even_freq) {
                max2_even = max1_even_freq;
                max1_even_freq = freq;
                max1_even_val = num;
            } else if(freq > max2_even) {
                max2_even = freq;
            }
        }

        for(auto [num, freq] : odd_fm) {
            if(freq > max1_odd_freq) {
                max2_odd = max1_odd_freq;
                max1_odd_freq = freq;
                max1_odd_val = num;
            } else if(freq > max2_odd) {
                max2_odd = freq;
            }
        }

        if(max1_even_val != max1_odd_val) {
            return (even_n - max1_even_freq) + (odd_n - max1_odd_freq);
        } else {
            return std::min((even_n - max1_even_freq) + (odd_n - max2_odd), (even_n - max2_even) + (odd_n - max1_odd_freq));
        }
    }
};
