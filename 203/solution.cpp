/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        if(head == nullptr) return nullptr;

        ListNode *start = new ListNode(0, head);
        ListNode *it = start;
        while(it && it->next != nullptr) {
            if(it->next->val == val) {
                ListNode *new_next = it->next->next;
                delete it->next;
                it->next = new_next;
            } else {
                it = it->next;
            }
        }

        return start->next;
    }
};
