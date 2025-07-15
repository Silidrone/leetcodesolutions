class MyCalendarThree {
public:
    std::map<int, int> bookings;

    MyCalendarThree() {
        
    }
    
    int book(int startTime, int endTime) {
        bookings[startTime]++;
        bookings[endTime]--;

        int booking_count = 0;
        int max_booking_count = 0;
        for(auto it = bookings.begin(); it != bookings.end(); ++it) {
            booking_count += it->second;
            if(booking_count > max_booking_count) {
                max_booking_count = booking_count;
            }
        }

        return max_booking_count;
    }
};
