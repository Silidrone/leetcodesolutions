#include <unordered_map>
#include <queue>

class Solution {
public:
    vector<int> topKFrequent(std::vector<int>& nums, int k) {
        std::unordered_map<int, int> val_freq_map;
    
        for(auto &n : nums) {
            val_freq_map[n]++;
        }

        using _pair = std::pair<int, int>; 
        std::priority_queue<_pair, std::vector<_pair>, std::greater<_pair>> minheap;
        auto it = val_freq_map.begin();
        for(int i = 0; i < k; ++i, ++it) { // k is ALWAYS <= val_freq_map.size() by constraints
            minheap.push(std::make_pair(it->second, it->first));
        }
        
        for(; it != val_freq_map.end(); ++it) {
            if(it->second > minheap.top().first) {
                minheap.pop();
                minheap.push(std::make_pair(it->second, it->first));
            }            
        }

        std::vector<int> result;

        while(!minheap.empty()) {
            result.push_back(minheap.top().second);
            minheap.pop();
        }

        return result;
    }
};
