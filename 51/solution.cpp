class Solution {
public:
    using Board = std::vector<std::string>;

    const char QUEEN = 'Q';
    const char EMPTY = '.';
    
    int m_n;
    std::vector<bool> m_attacked_cols;
    std::vector<bool> m_attacked_diag;
    std::vector<bool> m_attacked_anti_diag;
    Board m_board;
    std::vector<Board> m_solutions;

    void change_attacked(int r, int c, bool val) {
        m_attacked_cols[c] = val;
        m_attacked_diag[r - c + (m_n - 1)] = val;
        m_attacked_anti_diag[r + c] = val;
    }
    
    void attack(int r, int c) {
        change_attacked(r, c, true);
    }
    
    void unattack(int r, int c) {
        change_attacked(r, c, false);
    }
    
    bool is_attacked(int r, int c) {
        return m_attacked_cols[c] || m_attacked_diag[r - c + (m_n - 1)] || m_attacked_anti_diag[r + c];
    }

    void solve_with_dfs(int r = 0) {
        if(r == m_n) {
            m_solutions.push_back(m_board);
            return;
        }
        
        for(int c = 0; c < m_n; c++) {
            if(m_board[r][c] != QUEEN && !is_attacked(r, c)) {
                m_board[r][c] = QUEEN;
                attack(r, c);

                solve_with_dfs(r + 1);

                m_board[r][c] = EMPTY;
                unattack(r, c);
            }
        }
    }

    std::vector<Board> solveNQueens(int n) {
        m_n = n;
        m_board.resize(n, std::string(n, EMPTY));
        m_attacked_cols.resize(n, false);
        m_attacked_diag.resize(2 * n - 1, false);
        m_attacked_anti_diag.resize(2 * n - 1, false);        
        solve_with_dfs();
        
        return m_solutions;
    }
};