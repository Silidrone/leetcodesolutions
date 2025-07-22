class Solution {
public:
    int maxSatisfaction(std::vector<int>& satisfaction) {
        std::sort(satisfaction.begin(), satisfaction.end(), [](int a, int b) {
            return a < b;
        });

        int ss = 0, ps = 0, ni = 0;
        for(int i = 0; i < satisfaction.size(); ++i) {
            if(satisfaction[i] >= 0) {
                ni = i;
                break;
            }
        }

        for(int i = satisfaction.size(); i >= 1; --i) {
            int n = satisfaction[i - 1];
            if(n >= 0) {
                ss += (i - ni) * n; 
                ps += n; 
            } else if(ps > -n) {
                ps += n;
                ss += ps;
            }
        }

        return ss;
    }
};
