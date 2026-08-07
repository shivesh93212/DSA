/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right)
 *         : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    int height(TreeNode* root) {
        if (root == NULL)
            return -1;

        return 1 + max(height(root->left), height(root->right));
    }

    void solve(TreeNode* root,
               vector<vector<string>>& ans,
               int row,
               int col,
               int h) {

        if (root == NULL)
            return;

        ans[row][col] = to_string(root->val);

        if (row == h)
            return;

        int gap = 1 << (h - row - 1);

        solve(root->left, ans, row + 1, col - gap, h);
        solve(root->right, ans, row + 1, col + gap, h);
    }

    vector<vector<string>> printTree(TreeNode* root) {

        int h = height(root);

        int rows = h + 1;
        int cols = (1 << (h + 1)) - 1;

        vector<vector<string>> ans(rows, vector<string>(cols, ""));

        solve(root, ans, 0, (cols - 1) / 2, h);

        return ans;
    }
};