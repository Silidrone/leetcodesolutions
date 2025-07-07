class Solution {
public:
    using AdjList = std::map<int, std::vector<int>>;
    using Int2DVector = std::vector<std::vector<int>>;

    bool dfs(AdjList &adj, int vertex, std::vector<bool> &visited, std::unordered_set<int> &path, std::vector<int> &result) {
        if (path.find(vertex) != path.end()) return false;
        if (visited[vertex]) return true;

        path.insert(vertex);
        visited[vertex] = true;

        auto adj_it = adj.find(vertex);
        if (adj_it != adj.end()) {
            auto &neighbors = adj_it->second;
            for (int neighbor : neighbors) {
                if (!dfs(adj, neighbor, visited, path, result)) {
                    return false;
                }
            }
        }

        path.erase(vertex);
        result.push_back(vertex);
        return true;
    }

    std::vector<int> findOrder(int numCourses, Int2DVector &pre) {
        AdjList adj;
        for (auto &e : pre) {
            adj[e[1]].push_back(e[0]);
        }

        std::vector<int> result;
        std::vector<bool> visited(numCourses, false);
        std::unordered_set<int> path;

        for (int i = 0; i < numCourses; ++i) {
            if (!dfs(adj, i, visited, path, result)) {
                return {};
            }
        }

        std::reverse(result.begin(), result.end());
        return result;
    }
};
