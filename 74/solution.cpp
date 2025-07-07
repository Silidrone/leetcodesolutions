class Solution {
    using Int2DVector = std::vector<std::vector<int>>&;
public:
    bool searchMatrix(Int2DVector& m, int t) {
        int l = 0, r = m.size() - 1;
        int mid;

        while (l <= r) {
            mid = l + (r - l) / 2;

            if (m[mid][0] == t) return true;

            if (t > m[mid][0]) {
                if (mid == m.size() - 1 || t < m[mid + 1][0]) {
                    break; 
                }
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }

        int row = mid;

        l = 0, r = m[0].size() - 1;

        while(l <= r) {
            int mid = l + (r - l) / 2;
            if(m[row][mid] == t) return true;

            if(t < m[row][mid]) {
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }

        return false;
    }
};
