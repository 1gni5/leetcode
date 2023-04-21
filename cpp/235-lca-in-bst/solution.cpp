/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // Initializing
        TreeNode* current = root;
        TreeNode *start, *end;

        // Order the two nodes
        if (p->val > q->val){start = q; end = p;}
        else {start = p; end = q;}

        // While value in not in [start; end] interval
        while (!(start->val <= current->val && end->val >= current->val))
        {
            if (current->val > end->val){current = current->left;}
            else {current = current->right;}
        }

        return current;
    }
};