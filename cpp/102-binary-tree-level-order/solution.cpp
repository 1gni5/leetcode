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
 #include <queue>
 using namespace std;

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result;
        vector<int> output;
        queue<TreeNode*> waiting;

        // Empty list
        if (!root) {return result;}        

        // Initializing
        waiting.push(root);
        waiting.push(nullptr);

        while(!waiting.empty()) {
            TreeNode* current = waiting.front();
            waiting.pop();

            if (current == nullptr) {
                result.push_back(output);
                output.clear(); // Reset vector

                // If element remains, add marker
                if (!waiting.empty()) {
                    waiting.push(nullptr);
                }
                continue;
            }

            // Insert value
            output.push_back(current->val);

            // Insert children
            if (current->left != nullptr) {waiting.push(current->left);}
            if (current->right != nullptr) {waiting.push(current->right);}
        }

        return result;
    }
};