class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        auto cmp = [](vector<int>& a, vector<int>& b) {
            return a[0] > b[0];
        };
        priority_queue<vector<int>, vector<vector<int>>, decltype(cmp)> pq(cmp);
        int n = nums.size();
        int maxi = INT_MIN;

        for (int i = 0; i < n; i++) {
            int minVal = nums[i][0];
            pq.push({minVal, i, 0});
            maxi = max(maxi, minVal);
        }

        vector<int> smallRange = {0, INT_MAX};
        while (true) {
            vector<int> top = pq.top();
            pq.pop();
            int minEl = top[0], listIndex = top[1], elIndex = top[2];

            if (maxi - minEl < smallRange[1] - smallRange[0]) {
                smallRange[0] = minEl;
                smallRange[1] = maxi;
            }

            if (elIndex == nums[listIndex].size() - 1)
                break;

            int nextVal = nums[listIndex][elIndex + 1];
            maxi = max(maxi, nextVal);
            pq.push({nextVal, listIndex, elIndex + 1});
        }
        return smallRange;
    }
};
static const auto kds = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return 0;
}();
