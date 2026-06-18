class Solution {
public:
    double angleClock(int hour, int minutes) {
        double minAngle = (6 * minutes);
        double hourAngle = (30 * hour) + (0.5 * minutes);
        double firstAngle = abs(hourAngle - minAngle);
        double secondAngle = 360 - firstAngle;

        return min(firstAngle, secondAngle);
    }
};
static const auto kds = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();
