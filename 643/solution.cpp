class Solution {
public:
    double avg(vector<int> &nums, int k) {
        double result = 0;
        for(int i = 0; i < k; i++) {
            result += nums[i];
        }
        return result / k;
    }

    double findMaxAverage(vector<int>& nums, int k) {
        double curr_avg = avg(nums, k);
        double max_avg = curr_avg;
        for(int i = 1; i <= nums.size() - k; i++) {
            curr_avg += static_cast<double>(nums[i + k - 1] - nums[i - 1]) / k; 
            if(curr_avg > max_avg) {
                max_avg = curr_avg;
            }
        }

        return max_avg;
    }
};
