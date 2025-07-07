class Solution {
public:
    using Grid = std::vector<std::vector<char>>;

    bool positionIsValid(Grid &grid, int r, int c) {
        return r >= 0 && r < grid.size() && c >= 0 && c < grid[r].size();
    }

    bool positionIsOnTheEdge(Grid &grid, int r, int c) {
        return r == 0 || c == 0 || r == grid.size() - 1 || c == grid.size() - 1;
    }

    bool isVisited(std::vector<std::pair<int, int>> &visited, int r, int c) {
        return std::find(visited.begin(), visited.end(), std::pair<int, int>(r, c)) != visited.end();
    }

    bool dfs(Grid &grid, int r, int c, std::vector<std::pair<int, int>> &visited) {
        visited.push_back({r, c});

        // left, right, up, down
        std::vector<std::pair<int, int>> directions = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};
        bool is_surrounded = true;
        for(auto &d : directions) {
            int next_r = r + d.first;
            int next_c = c + d.second;
            if(positionIsValid(grid, next_r, next_c) && grid[next_r][next_c] == 'O' && !isVisited(visited, next_r, next_c)) {
                if(positionIsOnTheEdge(grid, next_r, next_c)) {
                    return false;
                } else {
                    is_surrounded &= dfs(grid, next_r, next_c, visited);
                }
            }
        }

        return is_surrounded;
    }

    void solve(Grid& grid) {
        // dont traverse the edges
        for(int i = 1; i < grid.size() - 1; i++) {
            for(int j = 1; j < grid[i].size() - 1; j++) {
                std::vector<std::pair<int, int>> visited;
                if(grid[i][j] == 'O' && !isVisited(visited, i, j)) {
                    if(dfs(grid, i, j, visited)) {
                        for(auto &index_pair : visited) {
                            grid[index_pair.first][index_pair.second] = 'X';
                        }
                    }
                }
            }
        }
    }
};
