class Solution {
public:
    int maxStarSum(std::vector<int>& vals, std::vector<std::vector<int>>& edges, int k) {
        std::unordered_map<int, std::vector<int>> adj;

        for(auto& edge : edges) {
            if(vals[edge[1]] > 0) {
                adj[edge[0]].push_back(edge[1]);
            }
            if(vals[edge[0]] > 0) {
                adj[edge[1]].push_back(edge[0]);
            }
        }

        for(auto& e : adj) {
            std::sort(e.second.begin(), e.second.end(), [&vals](int a, int b){
                return vals[a] > vals[b];
            });
        }

        int max_star_sum = INT_MIN;
        for(int i = 0; i < vals.size(); i++) {
            int star_sum = vals[i];
            if(adj.find(i) != adj.end()) {
                auto& neighbours = adj[i]; 
                for(int j = 0; j < k && j < neighbours.size(); j++) {
                    star_sum += vals[neighbours[j]];
                }
            }

            max_star_sum = std::max(max_star_sum, star_sum);
        }

        return max_star_sum;
    }
};
