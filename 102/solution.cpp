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
    vector<vector<int>> levelOrder(TreeNode* root) {
        std::vector<std::vector<int>> r;
        if(root == nullptr) return r;

        std::queue<std::pair<int, TreeNode*>> q;
        q.push({0, root});
        int level = 0;
        while(!q.empty()) {
            auto pair = q.front();
            q.pop();
            if(r.size() <= pair.first) {
                r.push_back({});
            }
            r[pair.first].push_back(pair.second->val);
            if(pair.second->left) {
                q.push({pair.first + 1, pair.second->left});
            }
            if(pair.second->right) {
                q.push({pair.first + 1, pair.second->right});
            }
        }

        return r;
    }
};
