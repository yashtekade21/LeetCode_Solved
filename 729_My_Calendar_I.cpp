class MyCalendar {
public:
    // set<pair<int,int>> vp;
    map<int,int> mp;
    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
        // for(auto s : vp)
        // {
        //     if(start < s.second && end > s.first)
        //         return false;
        // }
        // vp.insert({start,end});
        // return true;

        auto floor = mp.lower_bound(start);

        if(floor!=mp.begin() && prev(floor)->second > start) 
            return false;

        if(floor!=mp.end() && floor->first<end)
            return false;

        mp.insert({start,end});
        return true;
    }
};

static const auto kds = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return 0;
}();

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */
