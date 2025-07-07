class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow, fast;
        for(slow = nums[nums[0]], fast = nums[nums[nums[0]]]; slow != fast; slow = nums[slow], fast = nums[nums[fast]]);
        for(slow = nums[0]; slow != fast; slow = nums[slow], fast = nums[fast]);
        return slow;
    }
};
