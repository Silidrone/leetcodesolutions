class NumMatrix {
public:
    std::vector<std::vector<int>> sum_matrix;
    int n, m;

    NumMatrix(std::vector<std::vector<int>>& matrix) {
        n = matrix.size(), m = matrix[0].size();
        sum_matrix = std::vector<std::vector<int>>(n + 1, std::vector<int>(m + 1, 0));

        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= m; j++) {
                sum_matrix[i][j] = matrix[i - 1][j - 1] + sum_matrix[i][j - 1] + sum_matrix[i - 1][j] - sum_matrix[i - 1][j - 1];
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        return sum_matrix[row2 + 1][col2 + 1] - sum_matrix[row1][col2 + 1] - sum_matrix[row2 + 1][col1] + sum_matrix[row1][col1];
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */
