std::pair<int, int> operator+(const std::pair<int, int>& p1, const std::pair<int, int>& p2) {
    return {p1.first + p2.first, p1.second + p2.second};
}

std::vector<std::pair<int, int>> directions = {
    {-1, 0}, // down
    {1, 0}, // up
    {0, -1}, // left
    {0, 1} // right
};

class Solution {
private:
    const int EMPTY = 0;
    const int FRESH = 1;
    const int ROTTEN = 2;
public:
    using Coordinate = std::pair<int, int>;
    using OrangeGrid = vector<vector<int>>; 
    bool is_valid(Coordinate c, OrangeGrid &g) {
        return c.first >= 0 && c.first < g.size() && c.second >= 0 && c.second < g[0].size();
    }
    
    int orangesRotting(OrangeGrid& grid) {
        int total_fresh = 0;
        std::queue<std::pair<Coordinate, int>> q;
        for(int i = 0; i < grid.size(); ++i) {
            for(int j = 0; j < grid[0].size(); ++j) {
                if(grid[i][j] == ROTTEN) {
                    q.push({{i, j}, 0});
                } else if(grid[i][j] == FRESH) {
                    ++total_fresh;
                }
            }
        }

        if(q.empty()) {
            if(total_fresh > 0) {
                return -1;
            } else {
                return 0;
            }
        }

        int result = 0;
        int rotted_fresh = 0;
        while(!q.empty()) {
            auto front = q.front();
            result = front.second;
            
            q.pop();

            for(auto &d : directions) {
                auto neighbor_c = front.first + d;
                if(is_valid(neighbor_c, grid)) {
                    auto &neighbor = grid[neighbor_c.first][neighbor_c.second];
                    if(neighbor == FRESH) {
                        neighbor = ROTTEN;
                        q.push({neighbor_c, result + 1});
                        ++rotted_fresh;
                    }
                }
            }
        }

        return rotted_fresh == total_fresh ? result : -1;
    }
};
