class Solution {
public:
    int dfs(int max_weight, vector<vector<pair<int, int>>>& adj_list, vector<bool> &visited, int node = 0) {
        visited[node] = true;

        int nodes_visited = 1;
        for(auto &neighbour : adj_list[node]) {
            auto next_node = neighbour.first;
            auto edge_weight = neighbour.second;
            if(edge_weight <= max_weight && !visited[next_node]) {
                nodes_visited += dfs(max_weight, adj_list, visited, next_node);
            }
        }

        return nodes_visited;
    }

    int minMaxWeight(int n, vector<vector<int>>& edges, int threshold) {
        vector<vector<pair<int, int>>> reverse_adj_list(n);
        for(auto &edge : edges) {
            auto node_A = edge[0];
            auto node_B = edge[1];
            auto weight = edge[2];
            reverse_adj_list[node_B].push_back({node_A, weight});
        }

        int l = 1, r = 1000001;
        while(l < r) {
            int m = l + (r - l) / 2;
            vector<bool> visited(n, false);
            if(dfs(m, reverse_adj_list, visited) == n) {
                r = m;
            } else {
                l = m + 1;
            }
        }

        return l == 1000001 ? -1 : l;
    }
};
