class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        std::stack<int> monotonic_stack;
        std::vector<int> result(temperatures.size(), 0);

        for(int i = 0; i < temperatures.size(); ++i) {
            int t = temperatures[i];
            while(!monotonic_stack.empty() && t > temperatures[monotonic_stack.top()]) {
                int top_idx = monotonic_stack.top();
                result[top_idx] = i - top_idx;
                monotonic_stack.pop(); 
            }

            monotonic_stack.push(i);
        }

        return result;
    }
};
