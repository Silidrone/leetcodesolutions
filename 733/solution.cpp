class Solution {
public:
    using Color = int;
    using ImageGrid = std::vector<std::vector<Color>>;
    using GridPosition = std::pair<int, int>; 

    Color get_color(ImageGrid &grid, GridPosition &p) {
        return grid[p.first][p.second];
    }

    bool is_valid(ImageGrid &grid, GridPosition &p) {
        return p.first >= 0 && p.first < grid.size() && p.second >= 0 && p.second < grid[p.first].size(); 
    }

    void change_color(ImageGrid &grid, GridPosition &p, Color c) {
        grid[p.first][p.second] = c;
    }

    GridPosition add(GridPosition &a, GridPosition &b) {
        return {a.first + b.first, a.second + b.second};
    }

    void dfs(ImageGrid& grid, GridPosition start, Color color) {
        auto start_cell_color = get_color(grid, start); 
        change_color(grid, start, color);
        
        // left, right, up, down
        std::vector<GridPosition> directions = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};
        for(auto &direction : directions) {
            auto next_cell = add(start, direction);
            if(is_valid(grid, next_cell)) {
                auto next_cell_color = get_color(grid, next_cell);                
                if(next_cell_color != color && next_cell_color == start_cell_color) {
                    dfs(grid, next_cell, color);                    
                }
            }
        }
    }

    ImageGrid floodFill(ImageGrid& image, int sr, int sc, Color color) {
        GridPosition start = {sr, sc};
        if(is_valid(image, start)) {
            dfs(image, start, color);
        }

        return image;
    }
};
