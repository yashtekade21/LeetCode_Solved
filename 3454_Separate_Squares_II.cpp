class Solution {
public:
    struct Event {
        int y;
        int type, x1, x2;

        bool operator<(const Event& event) const { return y < event.y; }
    };

    double separateSquares(vector<vector<int>>& squares) {
        vector<Event> events;
        for (auto& s : squares) {
            int x = s[0];
            int y = s[1];
            int len = s[2];

            events.push_back({y, 1, x, x + len});
            events.push_back({y + len, -1, x, x + len});
        }

        sort(events.begin(), events.end());

        vector<pair<int, int>> intervals;
        vector<tuple<int, double, double>> stripes;

        double totalArea = 0;
        int prevY = events[0].y;
        for (auto& event : events) {
            if (event.y > prevY) {
                double width = getUnionWidth(intervals);

                double height = event.y - prevY;
                if (width > 0) {
                    stripes.push_back({prevY, height, width});
                    totalArea += (width * height);
                }
            }
            if (event.type == 1) {
                intervals.push_back({event.x1, event.x2});
            } else {
                for (auto it = intervals.begin(); it != intervals.end(); ++it) {
                    if (it->first == event.x1 && it->second == event.x2) {
                        intervals.erase(it);
                        break;
                    }
                }
            }
            prevY = event.y;
        }

        double half = totalArea / 2.0;
        double curArea = 0;

        for (auto& stripe : stripes) {
            int y;
            double height, width;
            tie(y, height, width) = stripe;
            double stripeArea = height * width;

            if (curArea + stripeArea >= half) {
                double req = half - curArea;

                return y + (req / width);
            }

            curArea += stripeArea;
        }

        return 0;
    }

private:
    double getUnionWidth(vector<pair<int, int>>& intervals) {
        if (intervals.empty())
            return 0.0;

        sort(intervals.begin(), intervals.end());

        double width = 0;

        int curLeft = intervals[0].first;
        int curRight = intervals[0].second;

        for (int i = 1; i < intervals.size(); i++) {
            if (intervals[i].first > curRight) {
                width += curRight - curLeft;

                curLeft = intervals[i].first;
                curRight = intervals[i].second;
            } else {
                curRight = max(curRight, intervals[i].second);
            }
        }
        width += curRight - curLeft;
        return width;
    }
};
static const auto kds = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();
