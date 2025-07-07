class Solution {
public:
    int bs_lb(std::vector<int>& v, int e) {
        int l = 0, r = v.size();
        while(l < r) {
            int m = l + (r - l) / 2;
            if(v[m] >= e) {
                r = m;
            } else {
                l = m + 1;
            }
        }
        
        return l;
    }

    int minOperations(std::vector<int>& target, std::vector<int>& arr) {
        std::unordered_map<int, int> target_indices;
        for(int i = 0; i < target.size(); i++) target_indices[target[i]] = i;
        
        std::vector<int> lis;
        for(auto& a : arr) {
            if(target_indices.find(a) == target_indices.end()) continue;
            int idx = bs_lb(lis, target_indices[a]);
            if(idx == lis.size()) lis.push_back(target_indices[a]);
            else lis[idx] = target_indices[a];
        }
        
        return target.size() - lis.size();
    }
};
