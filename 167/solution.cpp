class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int l = 0, r = numbers.size() - 1, pair_sum = 0;
        do {
            pair_sum = numbers[l] + numbers[r];
            if(pair_sum < target) {
                l++;
            } else if(pair_sum > target) {
                r--;
            }
        } while(pair_sum != target);

        return {l + 1, r + 1};
    }
};
