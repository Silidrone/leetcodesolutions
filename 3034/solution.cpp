class Solution {
public:
    int countMatchingSubarrays(vector<int>& nums, vector<int>& pattern) {
        int subarray_size = pattern.size() + 1;
        int result = 0;
        for(int i = 0; i < nums.size() - subarray_size + 1; i++) {
            bool pattern_satisfied = true;
            // subarray loop
            for(int j = i; j < i + pattern.size(); j++) {
                int first_num = nums[j];
                int second_num = nums[j + 1];
                int pattern_num = pattern[j - i];
                pattern_satisfied &= ((pattern_num == 1 && second_num > first_num) || (pattern_num == 0 && second_num == first_num) || (pattern_num == -1 && second_num < first_num));
            }

            if(pattern_satisfied) result++;
        }

        return result;
    }
};
