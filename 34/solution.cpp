class Solution {
public:
    std::vector<int> searchRange(std::vector<int>& nums, int target) {
       int l = 0, r = nums.size();
       bool found = false;
       while(l < r) {
         int m = l + (r - l) / 2;
         if(target < nums[m]) {
            r = m;
         } else {
            if(target == nums[m]) found = true;
            l = m + 1;
         }
       }

       if(!found) return {-1, -1};

       int end = l - 1;
       
       l = 0, r = nums.size();
       
       while(l < r) {
         int m = l + (r - l) / 2;
         if(target <= nums[m]) {
            r = m;
         } else {
            l = m + 1;
         }
       }
       
       int start = l;
       
       return {start, end};     
    }
};
