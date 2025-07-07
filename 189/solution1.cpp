class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        std::list<int> ll; // doubly linked list

        // time complexity: O(n)
        for(int &num : nums) {
            ll.push_back(num);
        }

        // time complexity: O(k)
        for(int i = 0; i < k; i++) {
            ll.push_front(ll.back());
            ll.pop_back();
        }

        // time complexity: O(n)
        int i = 0;
        for(int &num : ll) {
            nums[i] = num;
            i++;
        }
    }
};
