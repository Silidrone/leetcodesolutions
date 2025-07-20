#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>

class Solution {
public:
    using Grid = std::vector<std::vector<int>>;
    
    int rhombus_sum(int i, int j, int n, Grid& g) {
        int k = n / 4;
        int sum = g[i][j] + g[i][j + 2 * k] + g[i - k][j + k] + g[i + k][j + k];
        for(int z = 1; z < k; z++) {
            sum += g[i + z][j + z] + g[i + z][j + 2 * k - z] + g[i - z][j + z] + g[i - z][j + 2 * k - z];
        }

        return sum;
    }

    // (i, j) is the leftmost point of the rhombus with area n
    bool is_valid_rhombus(int i, int j, int area, Grid& g) {
        int m = g.size(), n = g[0].size(), k = area / 4;

        return 2 * k < n - j && i >= k && k < m - i;
    }

    std::vector<int> getBiggestThree(Grid& grid) {
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
