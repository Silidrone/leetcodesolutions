class MyCalendar {
protected:
    using Interval = std::pair<int, int>;
    struct Cmp {
        bool operator()(const Interval& a, const Interval& b) const {
            return a.first < b.first;
        }
    };
    
    std::set<Interval, Cmp> events;

public:
    MyCalendar() {}

    bool book(int cs, int ce) {
        if (cs > ce) return false;

        auto it = events.lower_bound({ce, 0});

        if (it != events.begin()) {
            auto prev = std::prev(it);
            if (prev->second > cs) return false;
        }

        events.insert({cs, ce});
        return true;
    }
};
