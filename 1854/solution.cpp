class Solution {
public:
    const int MIN_YEAR = 1950;
    const int MAX_YEAR = 2050;

    int maximumPopulation(vector<vector<int>>& logs) {
        std::vector<int> d(MAX_YEAR - MIN_YEAR + 1, 0);
        
        for(int i = 0; i < logs.size(); i++) {
            int birth = logs[i][0];
            int death = logs[i][1];
            d[birth - MIN_YEAR]++;
            d[death - MIN_YEAR]--;
        }

        for(int i = 1; i < d.size(); i++) {
            d[i] += d[i - 1];
        }

        int max_i = 0;
        int max = 0;
        for(int i = 0; i < d.size(); i++) {
            if(max < d[i]) {
                max = d[i];
                max_i = i;  
            }
        }

        return MIN_YEAR + max_i;
    }
};
