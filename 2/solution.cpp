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
#include <cmath>

class Solution {
protected:
    
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *sum_it = nullptr, *result = nullptr;
        int overflow = 0;
        ListNode *it1 = l1, *it2 = l2;
        while(it1 != nullptr || it2 != nullptr) {
            if(sum_it == nullptr) result = sum_it = new ListNode();
            else {
                sum_it->next = new ListNode();
                sum_it = sum_it->next;
            }
            int sum_val = (it1 ? it1->val : 0) + (it2 ? it2->val : 0) + overflow;
            sum_it->val = sum_val % 10;
            overflow = floor(sum_val / 10);
            it1 = it1 ? it1->next : nullptr;
            it2 = it2 ? it2->next : nullptr;
        }
        
        if(overflow > 0) {
            sum_it->next = new ListNode();
            sum_it->next->val = overflow;
        }
        
        return result;
    }
};
