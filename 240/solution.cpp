class Solution {
public:
    using Int2DVector = std::vector<std::vector<int>>;

    bool searchMatrix(Int2DVector &m, int t) {
        int r = 0, c = m[r].size() - 1;
        
        while(r < m.size() && c < m[r].size()) {
            if(t > m[r][c]) {
                r++;
            } else if(t < m[r][c]) {
                c--;
            } else {
                return true;
            }
        }

        return false;
    }
};
