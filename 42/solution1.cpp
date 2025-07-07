#include <numeric>


class Solution {
public:
    int trap(vector<int>& height) {
        if(height.size() <= 2) return 0;

        int gaps_count = 0;
        for(int i = 0; i < height.size(); i++) {
            if(height[i] > 0) {
                int j = i + 1;
                std::vector<int> gaps;
                while(j < height.size()) {
                    if(height[j] >= height[i]) {
                        gaps_count += std::accumulate(gaps.begin(), gaps.end(), 0); 
                        break;
                    } else {
                        int hdiff = height[i] - height[j];
                        for(int k = 0; k < gaps.size(); k++) {
                            if(hdiff < gaps[k]) {
                                gaps_count += gaps[k] - hdiff;
                                gaps[k] = hdiff; 
                            }
                        }

                        gaps.push_back(hdiff);
                        j++;
                    }
                }
                i = j - 1;
            }
        }
        return gaps_count;
    }
};
