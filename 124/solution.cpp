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
    int tree_sum(TreeNode* root, int &maxSum) {
        if(root == nullptr) return 0;

        int sum_l = std::max(0, tree_sum(root->left, maxSum));
        int sum_r = std::max(0, tree_sum(root->right, maxSum));

        if(root->val + sum_l + sum_r > maxSum) {
            maxSum = root->val + sum_l + sum_r;
        }

        return root->val + std::max(sum_l, sum_r);
    }

    int maxPathSum(TreeNode* root) {
        int maxSum = INT_MIN;
        tree_sum(root, maxSum);

        return maxSum;
    }
};
