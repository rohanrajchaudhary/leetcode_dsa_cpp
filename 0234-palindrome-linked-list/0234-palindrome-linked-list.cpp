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
    bool isPalindrome(ListNode* head) {
        if(head == nullptr || head->next == nullptr)
        {
            return true;
        }
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast->next != nullptr && fast->next->next != nullptr)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
            ListNode* second = slow->next;
            slow->next = nullptr;
            ListNode* prev = nullptr;
            ListNode* current = second;
        while(current != nullptr)
        {
            ListNode* next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }
        second = prev;
        ListNode* first = head;
        while(second != nullptr)
        {
            if(first->val != second->val)
            {
                return false;
            }
            first = first->next;
            second = second->next;
        }
        return true;
        
    }
};