class MyCalendarTwo {
public:
    vector<pair<int, int>> events;
    vector<pair<int, int>> overlap;

    MyCalendarTwo() {}

    bool book(int start, int end) {
        for (auto o : overlap) {
            if (max(start, o.first) < min(end, o.second))
                return false;
        }
        for (auto e : events) {
            if (max(start, e.first) < min(end, e.second)) {
                overlap.emplace_back(max(start, e.first), min(end, e.second));
            }
        }
        events.emplace_back(start, end);
        return true;
    }
};

static const auto kds = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();
/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(start,end);
 */
