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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* h1 = list1;
        ListNode* h2 = list2;
        ListNode* r = nullptr;

        if (h1 == nullptr && h2 == nullptr) {return nullptr;}
        if (h1 == nullptr) {return h2;} if (h2 == nullptr) {return h1;}

        // Initialize the resulting list
        if (h1->val < h2->val) {
            r = new ListNode(h1->val);
            h1 = h1->next;
        } else {
            r = new ListNode(h2->val);
            h2 = h2->next;
        }

        ListNode* result = r;

        // Merge the two lists
        while (h1 != nullptr && h2 != nullptr) {
            ListNode* tmp;
            if (h1->val < h2->val) {
                tmp = new ListNode(h1->val);
                h1 = h1->next;
            } else {
                tmp = new ListNode(h2->val);
                h2 = h2->next;
            }

            // Update results 
            r->next = tmp;
            r = r->next;
        }

        // Add remaining nodes
        while (h1 != nullptr) {
            r->next = new ListNode(h1->val);
            r = r->next;
            h1 = h1->next;
        }
        while (h2 != nullptr) {
            r->next = new ListNode(h2->val);
            r = r->next;
            h2 = h2->next;
        }

        return result;
    }
};
