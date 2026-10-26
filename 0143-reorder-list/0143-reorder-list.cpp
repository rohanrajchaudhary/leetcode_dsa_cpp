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
    void reorderList(ListNode* head) {
        if(head == nullptr || head->next == nullptr)
        {
            return;
        }
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast != nullptr && fast->next != nullptr)
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
            ListNode* next1 = first->next;
            ListNode* next2 = second->next;
            first->next = second;
            second->next = next1;
            first = next1;
            second = next2;
        }
    }
};