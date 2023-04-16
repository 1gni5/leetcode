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
        // Check for empty list
        if (head == nullptr){return head;}
        
        // Check for singleton
        if (head->next == nullptr){return head;}

        ListNode *previous=nullptr, *current=head, *next;
        while(current->next != nullptr) {
            next = current->next;
            current->next = previous;

            previous = current;
            current = next;
        }

        // Link last element
        current->next = previous;
        return current;
    }
};
