class Solution {
public:
    int largestRectangleArea(vector<int>& h) {
        std::stack<std::pair<int, int>> s; //monotonic stack, (index, height)

        int largest_area = 0;
        for(int i = 0; i < h.size(); i++) {
            int last_popped_idx = -1;
            for(; !s.empty() && h[i] < s.top().second; s.pop()) {
                int rectangle_area = (i - s.top().first) * s.top().second;
                if(largest_area < rectangle_area) {
                    largest_area = rectangle_area;
                }
                last_popped_idx = s.top().first;
            }
            

            s.push({last_popped_idx != -1 ? last_popped_idx : i, h[i]});
        }

        for(; !s.empty(); s.pop()) {
            int rectangle_area = (h.size() - s.top().first) * s.top().second;
            if(largest_area < rectangle_area) {
                largest_area = rectangle_area;
            }
        }

        return largest_area;
    }
};
