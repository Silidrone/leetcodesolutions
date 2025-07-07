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
    void preOrderPaths(TreeNode* root, std::vector<std::string> &paths, std::string path = "") {
        path += std::to_string(root->val);
        if(root->left == nullptr && root->right == nullptr) {
            paths.push_back(path);
            return;
        }
        if(root->left != nullptr) {
            preOrderPaths(root->left, paths, path + "->");
        }
        if(root->right != nullptr) {
            preOrderPaths(root->right, paths, path + "->");
        }
    }

    std::vector<std::string> binaryTreePaths(TreeNode* root) {
        std::vector<std::string> paths;
        preOrderPaths(root, paths);

        return paths;
    }
};
