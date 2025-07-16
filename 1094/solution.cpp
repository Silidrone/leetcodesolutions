class Solution {
public:
    const int MAX_TO = 1000;
    const int MIN_TO = 1;

    bool carPooling(std::vector<std::vector<int>>& trips, int capacity) {
        std::vector<int> d(MAX_TO + 1, 0);

        for(auto &trip : trips) {
            d[trip[1]] -= trip[0];
            d[trip[2]] += trip[0];
        }

        for(auto& e : d) {
            capacity += e;
            if(capacity < 0) {
                return false;
            }
        }

        return true;
    }
};
