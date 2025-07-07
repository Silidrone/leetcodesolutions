#include <vector>
#include <algorithm>

class Solution {
public:
    using Interval = std::vector<int>;

    int eraseOverlapIntervals(std::vector<Interval>& intervals) {
        std::sort(intervals.begin(), intervals.end(), [](Interval &a, Interval &b) {
            return a[1] < b[1];
        });

        int r = 0;
        for(int i = 1, last_end = intervals[0][1]; i < intervals.size(); i++) {
            if(intervals[i][0] < last_end) r++;
            else last_end = intervals[i][1];
        }

        return r;
    }
};
