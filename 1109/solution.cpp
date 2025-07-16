class Solution {
public:
    std::vector<int> corpFlightBookings(std::vector<std::vector<int>>& bookings, int n) {
        std::vector<int> answer(n, 0);

        for(int i = 0; i < bookings.size(); i++) {
            int first = bookings[i][0];
            int last = bookings[i][1];
            int seats = bookings[i][2];

            answer[first - 1] += seats;
            if(last < n) {
                answer[last] -= seats;            
            }
        }

        for(int i = 1; i < n; i++) {
            answer[i] += answer[i - 1];
        }

        return answer;
    }
};
