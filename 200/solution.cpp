class Solution {
public:
    using Grid = std::vector<std::vector<char>>;
    const char LAND = '1';
    const char WATER = '0';
    bool positionIsValid(Grid &grid, int r, int c) {
        return r >= 0 && r < grid.size() && c >= 0 && c < grid[r].size();
    }

    void dfs(Grid &grid, int r, int c) {
        grid[r][c] = WATER;

        // left, right, up, down
        std::vector<std::pair<int, int>> directions = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};
        for(auto &d : directions) {
            int next_r = r + d.first;
            int next_c = c + d.second;
            if(positionIsValid(grid, next_r, next_c) && grid[next_r][next_c] == LAND) {
                dfs(grid, next_r, next_c);
            }
        }
    }

    int numIslands(Grid &grid) {
        int island_count = 0;
        for(int i = 0; i < grid.size(); i++) {
            for(int j = 0; j < grid[i].size(); j++) {
                if(grid[i][j] == LAND) {
                    dfs(grid, i, j);
                    island_count++;
                }
            }
        }

        return island_count;
    }
};
