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
    void rec(TreeNode *root, int targetSum, int sum, std::vector<int> &path, std::vector<std::vector<int>> &result) {
        if(root == nullptr) return;
        sum += root->val;
        path.push_back(root->val);

        if(root->left == nullptr && root->right == nullptr && sum == targetSum) { // leaf node
            result.push_back(path);
        }

        rec(root->left, targetSum, sum, path, result);
        rec(root->right, targetSum, sum, path, result);
        path.pop_back();
    }

    std::vector<std::vector<int>> pathSum(TreeNode* root, int targetSum) {
        std::vector<std::vector<int>> result;
        std::vector<int> path;
        rec(root, targetSum, 0, path, result);
        return result;
    }
};
