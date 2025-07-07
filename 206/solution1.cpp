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
    ListNode* reverseList(ListNode* head) {
        if(head == nullptr) return nullptr;

        ListNode *newHead;
        for(newHead = head; newHead->next != nullptr; newHead = newHead->next);
        reverseListHelper(head);
        
        return newHead;
    }
    
    ListNode* reverseListHelper(ListNode* head) {
        if(head->next == nullptr) return head;
        reverseListHelper(head->next)->next = head;

        head->next = nullptr;
        return head;
    }
    
};