class Solution {
public:

    string solve(TreeNode* root) {
        if (root == NULL) {
            return "";
        }

        string ans = to_string(root->val);

        if (root->left && root->right) {
            ans = ans + "(" + solve(root->left) + ")";
            ans = ans + "(" + solve(root->right) + ")";
        }
        else if (root->left && !root->right) {
            ans = ans + "(" + solve(root->left) + ")";
        }
        else if (!root->left && root->right) {
            ans = ans + "()";
            ans = ans + "(" + solve(root->right) + ")";
        }

        return ans;
    }

    string tree2str(TreeNode* root) {
        return solve(root);
    }
};