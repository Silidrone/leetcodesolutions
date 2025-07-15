// simplest solution
class MyCalendar {
protected:
    std::vector<std::pair<int, int>> events;

public:
    MyCalendar() {
        
    }
    
    bool book(int cs, int ce) {
        if(cs > ce) return false;

        for(auto& event : events) {
            int s = event.first;
            int e = event.second;

            if(ce > s && cs < e) {
                return false;
            }
        }

        events.push_back({cs, ce});
        return true;
    }
};
