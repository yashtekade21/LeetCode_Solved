#include <algorithm>
#include <queue>
#include <vector>

class Solution {
public:
    int smallestChair(vector<vector<int>>& times, int targetFriend) {
        int targetArrival = times[targetFriend][0];
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>>
            leaves;
        priority_queue<int, vector<int>, greater<>> chairs;
        int chairNo = 0;
        sort(times.begin(), times.end());

        for (auto time : times) {
            while (!leaves.empty() && leaves.top().first <= time[0]) {
                chairs.push(leaves.top().second);
                leaves.pop();
            }

            int curChair;
            if (chairs.empty())
                curChair = chairNo++;
            else {
                curChair = chairs.top();
                chairs.pop();
            }
            if (targetArrival == time[0])
                return curChair;

            leaves.push({time[1], curChair});
        }
        return -1;
    }
};
static const auto kds = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return 0;
}();
