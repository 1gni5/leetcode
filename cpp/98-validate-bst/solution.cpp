/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    vector<int> values;
    void in_order(TreeNode* root) {
        if (root->left) {in_order(root->left);}
        values.push_back(root->val);
        if (root->right) {in_order(root->right);}
    } 

    bool isValidBST(TreeNode* root) {
        in_order(root);
        for (int i = 0; i < values.size() - 1; i++) {
            if (values[i] >= values[i+1]) return false;
        }
        return true;
    }
};