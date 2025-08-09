class Solution {
public:
    int numRescueBoats(std::vector<int>& people, int limit) {
        std::sort(people.begin(), people.end());
        int i = 0, j = people.size() - 1, boats = 0;
        while(i <= j) {
            if (people[i] + people[j] <= limit) {
                i++;
            }

            j--;
            boats++;
        }

        return boats;
    }
};
