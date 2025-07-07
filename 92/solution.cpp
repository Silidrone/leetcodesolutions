class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (head == nullptr || head->next == nullptr || left == right) return head;

        ListNode *dummy = new ListNode(0);
        dummy->next = head;
        ListNode *pre_entrance = dummy;

        for (int i = 1; i < left; i++) {
            pre_entrance = pre_entrance->next;
        }

        ListNode *entrance = pre_entrance->next;
        ListNode *curr = entrance;
        ListNode *prev = nullptr;
        ListNode *next = nullptr;

        for (int i = left; i <= right; i++) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        pre_entrance->next = prev;
        entrance->next = curr;
        auto result = dummy->next;
        delete dummy;
        return result;
    }
};
