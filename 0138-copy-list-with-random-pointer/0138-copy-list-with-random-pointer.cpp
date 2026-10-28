/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head == nullptr)
        {
            return nullptr;
        }
        unordered_map<Node*,Node*>mp;
        Node* orig_val = head;
        while(orig_val != nullptr)
        {
            Node* copy = new Node(orig_val->val);
            mp[orig_val] = copy;
            orig_val = orig_val->next;
        }
        orig_val = head;
        while(orig_val != nullptr)
        {
            mp[orig_val]->next = mp[orig_val->next];
            mp[orig_val]->random = mp[orig_val->random];
            orig_val = orig_val->next;
        }
        return mp[head];

    }
};