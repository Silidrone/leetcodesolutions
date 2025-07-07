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

#include <stack>

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(head == nullptr || head->next == nullptr) return head;

        stack<ListNode *> node_stack;

        ListNode *it = head;
        while(it->next != nullptr) {
            node_stack.push(it);
            it = it->next;
        }
        ListNode *newHead = it;
        
        while(!node_stack.empty()) {
            ListNode *node = node_stack.top();
            it->next = node;
            it = node;
            node_stack.pop(); 
        }

        head->next = nullptr;

        return newHead;
    }
    
};