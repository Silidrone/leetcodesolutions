class Solution {
public:
    int get_reverse_pair_count(std::vector<int> &a, std::vector<int>& b) {
        int i = 0, j = 0, result = 0;

        while(i < a.size() && j < b.size()) {
            if(a[i] > b[j] * 2LL) {
                result += (a.size() - i);
                j++;
            } else {
                i++;
            }
        }

        return result;
    }

    std::vector<int> merge(std::vector<int> &a, std::vector<int> &b) {
        std::vector<int> result;

        int i = 0, j = 0;
        while(i < a.size() && j < b.size()) {
            if(a[i] <= b[j]) result.push_back(a[i++]);
            else result.push_back(b[j++]);
        }

        while(i < a.size()) result.push_back(a[i++]);
        while(j < b.size()) result.push_back(b[j++]);

        return result;
    }

    std::vector<int> ms_reversepairs(std::vector<int>& nums, int l, int r, int &reverse_pair_count) {
        if(r == l) return std::vector<int>{nums[l]};

        int m = l + (r - l) / 2;
        std::vector<int> a = ms_reversepairs(nums, l, m, reverse_pair_count);    
        std::vector<int> b = ms_reversepairs(nums, m + 1, r, reverse_pair_count);
        reverse_pair_count += get_reverse_pair_count(a, b);
        return merge(a, b);
    }

    int reversePairs(std::vector<int>& nums) {
        int reverse_pair_count = 0;
        ms_reversepairs(nums, 0, nums.size() - 1, reverse_pair_count);

        return reverse_pair_count;
    }
};
