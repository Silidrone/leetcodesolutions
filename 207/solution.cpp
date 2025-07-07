class Solution {
public:
    using AdjList = std::unordered_map<int, std::vector<int>>; 
    bool dfs(AdjList &adj, int vertex, std::unordered_set<int> &visited, std::unordered_set<int> &path) {        
        if(visited.find(vertex) != visited.end()) return true;
        visited.insert(vertex);
        path.insert(vertex);

        auto adj_it = adj.find(vertex);
        if(adj_it != adj.end()) {
            auto neighbors = adj_it->second;
            for(int i = 0; i < neighbors.size(); i++) {
                int neighbor = neighbors[i];
                if(path.find(neighbor) != path.end() || !dfs(adj, neighbor, visited, path)) {
                    return false;
                }
            }
        }

        path.erase(vertex);
        return true;
    }

    bool canFinish(int numCourses, vector<vector<int>>& pr) {
        if(pr.size() == 0 || numCourses == 0) return true;

        AdjList adj;
        for(auto &e : pr) {
            adj[e[0]].push_back(e[1]);
        }

        std::unordered_set<int> visited;
        std::unordered_set<int> path;
        bool result = true;
        for(auto &e : adj) {
            result &= dfs(adj, e.first, visited, path);
        }
        return result;
    }
};
