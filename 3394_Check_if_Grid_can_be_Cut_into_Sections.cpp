class Solution {
public:
    bool checkValidCuts(int n, vector<vector<int>>& rectangles) {
        int size = rectangles.size();
        vector<vector<int>> xAxis, yAxis;

        for (auto& rect : rectangles) {
            int sx = rect[0], ex = rect[2];
            int sy = rect[1], ey = rect[3];

            xAxis.push_back({sx, ex});
            yAxis.push_back({sy, ey});
        }
        sort(xAxis.begin(), xAxis.end());
        sort(yAxis.begin(), yAxis.end());

        vector<vector<int>> mergedX, mergedY;

        int i = 0;
        while (i < size) {
            int start = xAxis[i][0];
            int end = xAxis[i][1];
            while (i + 1 < size && end > xAxis[i + 1][0]) {
                end = max(end, xAxis[i + 1][1]);
                i++;
            }
            mergedX.push_back({start, end});
            i++;
        }

        if(mergedX.size() >= 3)
            return true;

        i = 0;
        while (i < size) {
            int start = yAxis[i][0];
            int end = yAxis[i][1];
            while (i + 1 < size && end > yAxis[i + 1][0]) {
                end = max(end, yAxis[i + 1][1]);
                i++;
            }
            mergedY.push_back({start, end});
            i++;
        }

        if (mergedY.size() >= 3) {
            return true;
        }
        return false;
    }
private:
    
};
static const auto kds = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();
