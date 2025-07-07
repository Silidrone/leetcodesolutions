#include <iostream>
#include <vector>
#include <climits>
#include <unordered_map>

class Solution {
public:
    int mind_bs(int s, int e, std::vector<int>& heaters, int house, int mind = INT_MAX) { // O(log n)
        if(s >= e) {
            return mind;
        }
        
        int m = s + (e - s) / 2;
        mind = std::min(abs(heaters[m] - house), mind);
        
        if(house < heaters[m]) { // branch left
            mind = mind_bs(s, m, heaters, house, mind);
        } else { // branch right
            mind = mind_bs(m + 1, e, heaters, house, mind);
        }
        
        return mind;
    }

    int findRadius(std::vector<int>& houses, std::vector<int>& heaters) { // O(n * log n)
        std::sort(heaters.begin(), heaters.end()); // O(n * log n)

        int max_mind = INT_MIN;
        for(auto &house : houses) { // O(n)
            int mind = mind_bs(0, heaters.size(), heaters, house);
            if(mind > max_mind) {
                max_mind = mind;
            }
        }

        return max_mind;
    }
};
