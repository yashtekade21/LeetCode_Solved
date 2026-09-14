class Solution {
public:
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
        int x1_1 = rec1[0], y1_1 = rec1[1], x2_1 = rec1[2], y2_1 = rec1[3];
        int x1_2 = rec2[0], y1_2 = rec2[1], x2_2 = rec2[2], y2_2 = rec2[3];

        return x1_1 < x2_2 && x2_1 > x1_2 && y1_1 < y2_2 && y2_1 > y1_2 ? true
                                                                        : false;
    }
};
static const auto kds = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();
