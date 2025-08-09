#include <vector>

class Solution {
public:
    using Grid = std::vector<std::vector<int>>;
    using VisitedGrid = std::vector<std::vector<bool>>;
    std::vector<std::pair<int, int>> directions = {
        {-1, 0},
        {1, 0},
        {0, -1},
        {0, 1}
    };

    bool is_valid(Grid& grid, int i, int j) {
        return i >= 0 && i < grid.size() && j >= 0 && j < grid[0].size();
    }

    bool dfs(Grid& grid, int i, int j, VisitedGrid &visited) {
        if(i == 0 || j == 0 || i == grid.size() - 1 || j == grid[0].size() - 1) return false;
        visited[i][j] = true;

        bool closed_island = true;

        for(auto& direction : directions) {
            int new_i = i + direction.first;
            int new_j = j + direction.second;
            
            if(is_valid(grid, new_i, new_j) && !visited[new_i][new_j] && !grid[new_i][new_j]) {
                closed_island &= dfs(grid, new_i, new_j, visited);
            }
        }

        return closed_island;
    }

    int closedIsland(Grid& grid) {
        VisitedGrid visited(grid.size(), std::vector<bool>(grid[0].size(), false));
        int closed_island_count = 0;
        for(int i = 1; i < grid.size() - 1; i++) {
            for(int j = 1; j < grid[i].size() - 1; j++) {
                if(!visited[i][j] && !grid[i][j] && dfs(grid, i, j, visited)) {
                    closed_island_count++;
                }
            }
        }

        return closed_island_count;
    }
};
