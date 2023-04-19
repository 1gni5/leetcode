/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

#include <stack>
using namespace std;

class Solution {
public:
    vector<int> preorder(Node* root) {
        vector<int> results;
        stack<Node*> waiting;

        // Empty tree
        if (!root) {return results;}

        // Initializing
        waiting.push(root);

        while (!waiting.empty()) {
            Node* current = waiting.top();
            waiting.pop();

            vector<Node*>& children = current->children;
            for (int i=children.size()-1; i >= 0; i--) {
                waiting.push(children[i]);
            }
            results.push_back(current->val);
        }
        return results;
    }
};