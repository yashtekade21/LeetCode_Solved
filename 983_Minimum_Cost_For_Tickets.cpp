class Solution {
public:
    vector<int> dp;
    Solution() : dp(366, -1) {};

    int mincostTickets(vector<int>& days, vector<int>& costs) {
        return find_min_cost(days, costs, 0);
    }

private:
    int find_min_cost(vector<int>& days, vector<int>& costs, int i) {
        if (i > days.size() - 1)
            return 0;

        if (dp[i] != -1)
            return dp[i];

        int cost1 = costs[0] + find_min_cost(days, costs, i + 1);

        int max_7_day = days[i] + 7;
        int j = i;
        while (j < days.size() && max_7_day > days[j])
            j++;

        int cost7 = costs[1] + find_min_cost(days, costs, j);

        int max_30_day = days[i] + 30;
        j = i;
        while (j < days.size() && max_30_day > days[j])
            j++;

        int cost30 = costs[2] + find_min_cost(days, costs, j);

        return dp[i] = min(cost1, min(cost7, cost30));
    }
};
static const auto kds = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();
