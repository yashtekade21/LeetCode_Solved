class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        vector<int> minsarr;

        for (int i = 0; i < timePoints.size(); i++) {
            int hour = stoi(timePoints[i].substr(0, 2));
            int mins = stoi(timePoints[i].substr(3,5));
            // cout<<hour<<" "<<mins<<endl;
            minsarr.emplace_back((hour * 60) + mins);
        }

        sort(minsarr.begin(), minsarr.end());

        int ans = INT_MAX;
        for (int i = 1; i < minsarr.size(); i++) {
            ans = min(ans, minsarr[i] - minsarr[i - 1]);
        }

        return min(ans, 24 * 60 - (minsarr[minsarr.size() - 1] - minsarr[0]));
    }
};

static const auto kds = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return 0;
}();
