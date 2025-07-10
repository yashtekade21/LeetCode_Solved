class Solution {
public:
    int maxFreeTime(int eventTime, vector<int>& startTime,
                    vector<int>& endTime) {
        vector<int> freeTimeArr;
        freeTimeArr.push_back(startTime[0] - 0);

        for (int i = 1; i < startTime.size(); i++)
            freeTimeArr.push_back(startTime[i] - endTime[i - 1]);

        freeTimeArr.push_back(eventTime - endTime[endTime.size() - 1]);

        int n = freeTimeArr.size();

        vector<int> rightMaxFree(n, 0), leftMaxFree(n, 0);

        for (int i = n - 2; i >= 0; i--)
            rightMaxFree[i] = max(rightMaxFree[i + 1], freeTimeArr[i + 1]);
        for (int i = 1; i < n; i++)
            leftMaxFree[i] = max(leftMaxFree[i - 1], freeTimeArr[i - 1]);

        int maxFreeTime = 0;

        for (int i = 1; i < n; i++) {
            int curDuration = endTime[i-1] - startTime[i-1];

            if (curDuration <= max(leftMaxFree[i - 1], rightMaxFree[i]))
                maxFreeTime =
                    max(maxFreeTime,
                        freeTimeArr[i - 1] + curDuration + freeTimeArr[i]);

            maxFreeTime = max(maxFreeTime, freeTimeArr[i - 1] + freeTimeArr[i]);
        }

        return maxFreeTime;
    }
};
static const auto kds = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();
