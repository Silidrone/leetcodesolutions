/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    void dfs(Node *originalNode, Node *copyNode, std::vector<Node *> &visited) {
        int idx = copyNode->val - 1;
        if(idx >= visited.size()) {
            visited.resize(idx + 1);
        }

        visited[idx] = copyNode;
        copyNode->neighbors = std::vector<Node *>();
        for(auto &neighbor : originalNode->neighbors) {
            int neighbor_idx = neighbor->val - 1;
            Node *newNeighbor = (neighbor_idx < visited.size()) ? visited[neighbor_idx] : nullptr;
            if(newNeighbor == nullptr) {
                newNeighbor = new Node(neighbor->val);
                dfs(neighbor, newNeighbor, visited);                
            }
            copyNode->neighbors.push_back(newNeighbor);
        }
    }

    Node* cloneGraph(Node* node) {
        if(node == nullptr) return nullptr;
        Node *deepCopyNode = new Node(node->val);
        std::vector<Node *> visited;
        dfs(node, deepCopyNode, visited);

        return deepCopyNode;
    }
};
