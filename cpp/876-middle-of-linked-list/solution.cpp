/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode *slow = head;
        ListNode *fast = head;

        // Iterate throught the list
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;

            // Cycle found !
            if (slow == fast) {
                // Reset slow pointer position
                slow = head;
                while (slow != fast) {
                    slow = slow->next;
                    fast = fast->next;
                }

                return slow;
            }
        }
        return nullptr;
    }
};