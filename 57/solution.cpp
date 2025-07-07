class Solution {
public:
    using Interval = std::vector<int>; // size == 2

    bool mergeIntervals(Interval &a, Interval &b) {
        if(a[0] <= b[1] && b[0] <= a[1]) {
            b[1] = std::max(b[1], a[1]);
            return true;
        } else {
            return false;
        }
    }

    vector<vector<int>> merge(vector<Interval>& intervals) {
        std::sort(intervals.begin(), intervals.end(), [](Interval &a, Interval &b) {
            return a[0] < b[0];
        });        

        std::vector<Interval> result;
        for(int i = 0, j = -1; i < intervals.size(); i++) {
            if(result.size() < 1 || !mergeIntervals(intervals[i], result[result.size() - 1])) {
                result.push_back(intervals[i]);
            }
        }

        return result;
    }

    std::vector<Interval> insert(std::vector<Interval>& intervals, Interval& new_interval) {
        if(intervals.size() == 0) {
            return std::vector<Interval>{new_interval};
        }

        int i;
        for(i = 0; i < intervals.size() && intervals[i][0] < new_interval[0]; i++);

        int insertion_point = i;
        intervals.resize(intervals.size() + 1);
        for(i = intervals.size() - 1; i > insertion_point; i--) {
            intervals[i] = intervals[i - 1];
        }
        intervals[insertion_point] = new_interval;

        return merge(intervals);
    }
};
