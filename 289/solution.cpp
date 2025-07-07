class Solution {
public:
    using Board = std::vector<std::vector<int>>;
    std::vector<std::pair<int, int>> directions = {
        {-1, 0},
        {1, 0},
        {0, -1},
        {0, 1},
        {-1, -1},
        {-1, 1},
        {1, -1},
        {1, 1}
    };

    static constexpr int DEAD = 0;
    static constexpr int LIVE = 1;
    
    int is_valid(int m, int n, int r, int c) {
        return r >= 0 && r < m && c >= 0 && c < n;
    }

    void applyGameRules(const Board& cb, Board& mb, int m, int n, int r, int c) {
        int live = 0, dead = 0;
        for(auto& direction : directions) {
            int n_r = r + direction.first;
            int n_c = c + direction.second;
            if(!is_valid(m, n, n_r, n_c)) continue;
            
            if(cb[n_r][n_c] == LIVE) live++;
            else dead++;
        }

        if(cb[r][c] == LIVE && (live < 2 || live > 3)) mb[r][c] = DEAD;
        else if(cb[r][c] == DEAD && live == 3) mb[r][c] = LIVE;
    }

    void gameOfLife(Board& board) {
        int m = board.size();
        int n = board[0].size();
        Board board_copy(m, std::vector<int>(n));
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                board_copy[i][j] = board[i][j];
            }
        }
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                applyGameRules(board_copy, board, m, n, i, j);
            }
        }
    }
};
