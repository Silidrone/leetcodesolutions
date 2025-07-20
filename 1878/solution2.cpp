#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>

class Solution {
public:
    using Grid = std::vector<std::vector<int>>;
    std::vector<std::vector<int>> up_right_sum;
    std::vector<std::vector<int>> up_left_sum;
    
    int rhombus_sum(int i, int j, int n, Grid& g) {
        int k = n / 4;
        return up_left_sum[i][j + 2 * k] - up_left_sum[i - k][j + k] + 
               up_right_sum[i][j] - up_right_sum[i - k][j + k] +  
               up_left_sum[i + k][j + k] - up_left_sum[i][j] +
               up_right_sum[i + k][j + k] - up_right_sum[i][j + 2 * k] +
               g[i + k][j + k] - g[i - k][j + k];
    }

    // (i, j) is the leftmost point of the rhombus with area n
    bool is_valid_rhombus(int i, int j, int area, Grid& g) {
        int m = g.size(), n = g[0].size(), k = area / 4;

        return 2 * k < n - j && i >= k && k < m - i;
    }
    
    void initialize_prefix_sum(Grid& g) {
        int m = g.size(), n = g[0].size();
        up_right_sum = std::vector<std::vector<int>>(m, std::vector<int>(n, 0));
        up_left_sum = std::vector<std::vector<int>>(m, std::vector<int>(n, 0));

        for(int i = 1; i < g.size(); i++) {
            for(int j = 0; j < g[0].size(); j++) {
                if(j != 0) up_left_sum[i][j] = up_left_sum[i - 1][j - 1] + g[i - 1][j - 1];
                if(j != g[0].size() - 1) up_right_sum[i][j] = up_right_sum[i - 1][j + 1] + g[i - 1][j + 1];
            }
        }
    }

    std::vector<int> getBiggestThree(Grid& grid) {
        initialize_prefix_sum(grid);
        std::priority_queue<int> pq;
        for(int i = 0; i < grid.size(); i++) {
            for(int j = 0; j < grid[0].size(); j++) {
                pq.push(grid[i][j]);
                for(int z = 4; is_valid_rhombus(i, j, z, grid); z += 4) {
                    pq.push(rhombus_sum(i, j, z, grid));
                }
            }
        }
        
        std::vector<int> vec;
        std::unordered_set<int> seen;

        while (!pq.empty() && vec.size() < 3) {
            int val = pq.top();
            pq.pop();
            if (seen.insert(val).second) {
                vec.push_back(val);
            }
        }

        return vec;
    }
};
