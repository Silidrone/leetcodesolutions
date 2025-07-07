class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        std::unordered_set<int> seen;
        for(int e : arr) {
            if(seen.count(e)) {
                return true;
            }
            if(e % 2 == 0) seen.insert(e / 2);
            seen.insert(e * 2);
        }
        return false;
    }
};
