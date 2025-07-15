class MyCalendar {
protected:
    std::vector<std::pair<int, int>> events;

public:
    MyCalendar() {
        
    }
    
    int bs_freeSlot(int cs, int ce) {
        int l = 0, r = events.size();
        while(l < r) {
            int m = l + (r - l) / 2;
            int s = events[m].first;
            int e = events[m].second;

            if(s < ce) {
                l = m + 1;
            } else {
                r = m;
            }
        }

        return l;
    }
    
    bool book(int cs, int ce) {
        if(cs > ce) return false;

        int idx = bs_freeSlot(cs, ce);

        if (idx > 0 && events[idx - 1].second > cs) return false;

        events.insert(events.begin() + idx, {cs, ce});
        return true;
    }
};
