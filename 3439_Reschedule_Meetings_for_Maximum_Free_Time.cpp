class Solution {
public:
    int maxFreeTime(int eventTime, int k, vector<int>& startTime,
                    vector<int>& endTime) {
        vector<int> freeTimeArr = {startTime[0] - 0};

        for (int i = 1; i < startTime.size(); i++)
            freeTimeArr.push_back(startTime[i] - endTime[i - 1]);

        freeTimeArr.push_back(eventTime - endTime[endTime.size() - 1]);

        int i = 0, j = 0;
        int maxFreeTime = 0;
        int curFreeTime = 0;

        while (j < freeTimeArr.size()) {
            curFreeTime += freeTimeArr[j];

            while (j - i > k) { // j- i + 1 > k + 1
                curFreeTime -= freeTimeArr[i];
                i++;
            }

            maxFreeTime = max(maxFreeTime, curFreeTime);
            j++;
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
