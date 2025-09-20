class Router {
public:
    set<vector<int>> st;
    queue<vector<int>> q;
    unordered_map<int, vector<int>> mp;
    int maxLimit = 0;

    Router(int memoryLimit) { maxLimit = memoryLimit; }

    bool addPacket(int source, int destination, int timestamp) {
        vector<int> newPacket = {source, destination, timestamp};

        if (st.find(newPacket) != st.end())
            return false;

        if (q.size() >= maxLimit) {
            vector<int> vec = q.front();
            q.pop();
            st.erase(vec);

            auto& timestamps = mp[vec[1]];
            if (!timestamps.empty() && timestamps.front() == vec[2])
                timestamps.erase(timestamps.begin());
        }

        q.push(newPacket);
        st.insert(newPacket);
        mp[destination].push_back(timestamp);
        return true;
    }

    vector<int> forwardPacket() {
        if (q.empty())
            return {};

        vector<int> vec = q.front();
        q.pop();
        st.erase(vec);

        int source = vec[0];
        int dest = vec[1];
        int timestamp = vec[2];

        auto& timestamps = mp[dest];
        auto it = lower_bound(timestamps.begin(), timestamps.end(), timestamp);
        if (it != timestamps.end() && *it == timestamp)
            timestamps.erase(it);

        return {source, dest, timestamp};
    }

    int getCount(int destination, int startTime, int endTime) {
        auto& timestamps = mp[destination];
        int l = lower_bound(timestamps.begin(), timestamps.end(), startTime) -
                timestamps.begin();
        int r = upper_bound(timestamps.begin(), timestamps.end(), endTime) -
                timestamps.begin();
        return r - l;
    }
};

/**
 * Your Router object will be instantiated and called as such:
 * Router* obj = new Router(memoryLimit);
 * bool param_1 = obj->addPacket(source,destination,timestamp);
 * vector<int> param_2 = obj->forwardPacket();
 * int param_3 = obj->getCount(destination,startTime,endTime);
 */
static const auto kds = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();
