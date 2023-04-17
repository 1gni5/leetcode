/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

#include <map>
using namespace std;

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        map<ListNode*, int> indexes;
        int index = 0;
        ListNode* current = head;

        // Check if the list if empty
        if (current == nullptr) {return nullptr;}

        while (current->next != nullptr) {
            // Check if nodes already visited
            if (indexes.count(current) > 0) {
                return current;
            }

            // Update history, index and pointer
            indexes[current] = index++;
            current = current->next;
        }

        return nullptr;
    }
};