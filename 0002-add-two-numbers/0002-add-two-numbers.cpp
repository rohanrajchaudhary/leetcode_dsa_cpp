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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode(0);
        ListNode* current = dummy;
        int carry = 0;
        while(l1 != nullptr || l2 != nullptr)
        {
            int val1 = 0;
            if(l1 != nullptr)
            {
                val1 = l1->val;
            }
            int val2 = 0;
            if(l2 != nullptr)
            {
                val2 = l2->val;
            }
            int sum = val1 + val2 + carry;
            carry = sum/10;
            int digit = sum%10;
            current->next = new ListNode(digit);
            current = current->next;
            if(l1 != nullptr)
            {
                l1 = l1->next;
            } 
            if(l2 != nullptr)
            {
                l2 = l2->next;
            }
        }
        if(carry != 0)
        {
            current->next = new ListNode(carry);
        }
        return dummy->next;
    }
};