class Solution {
public:
    int largestAltitude(std::vector<int>& gain) {
        int max_alt = 0;
        for(int i = 0, sum = 0; i < gain.size(); i++) {
            sum += gain[i];
            if(sum > max_alt) {
                max_alt = sum;
            }
        }

        return max_alt;
    }
};
