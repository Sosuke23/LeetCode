class MyCalendarTwo {
public:
    map<int, int> events;
    MyCalendarTwo() {
        
    }
    
    bool book(int startTime, int endTime) {
        events[startTime] += 1;
        events[endTime] -= 1;
        int cnt = 0;
        for (auto [_, c] : events) {
            cnt += c;
            if (cnt == 3) {
                events[startTime] -= 1;
                events[endTime] += 1;
                return false;
            }
        }
        return true;
    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(startTime,endTime);
 */