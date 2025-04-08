class RecentCounter {
public:
    int counter;
    queue<int> q;
    RecentCounter() { counter = 0; }

    int ping(int t) {
        q.push(t);
        int minRange = t - 3000;
        counter++;

        while (q.front() < minRange) {
            q.pop();
            counter--;
        }
        return counter;
    }
};
static const auto kds = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */
