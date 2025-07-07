class Solution {
public:
    int timeToEat(vector<int> piles, int k) {
        int result = 0;
        for(auto& pile : piles) {
            result += (pile == k) ? 1 : std::ceil((double)pile / k);
        }

        return result;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int max_pile = INT_MIN;
        for(auto &pile : piles) {
            if(pile > max_pile) {
                max_pile = pile;
            }
        }

        int l = 1, r = max_pile + 1;
        while(l < r) {
            int m = l + (r - l) / 2;
            if(timeToEat(piles, m) <= h) {
                r = m;
            } else {
                l = m + 1;
            }
        }

        return l;
    }
};
