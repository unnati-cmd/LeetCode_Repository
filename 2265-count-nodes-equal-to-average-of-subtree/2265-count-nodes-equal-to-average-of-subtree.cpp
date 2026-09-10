/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    int ans = 0;
    pair<int, int> solve(TreeNode* root) {
        if (root == NULL)
            return {0, 0};

        // descending downwards
        pair<int, int> left = solve(root->left);
        pair<int, int> right = solve(root->right);
        
        // ascending upwards
        int sum = left.first + right.first + root->val;
        int length = left.second + right.second + 1;

        int average = sum / length;
        if (average == root->val)
            ans++;

        return {sum, length};
    }
    int averageOfSubtree(TreeNode* root) {
        solve(root);
        return ans;
    }
};