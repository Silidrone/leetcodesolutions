/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *safe_next(ListNode *it) {
        if(it == nullptr) return nullptr;
        return it->next;
    }

    bool hasCycle(ListNode *head) {
        if(head == nullptr) return false;

        ListNode *slow_it = head;
        ListNode *fast_it = head->next;

        while(true) {
            if(slow_it == nullptr || fast_it == nullptr) return false;
            if(slow_it == fast_it) return true;

            slow_it = slow_it->next;
            fast_it = safe_next(fast_it->next);
        }

        return slow_it != nullptr && fast_it != nullptr && slow_it == fast_it;
    }
};
