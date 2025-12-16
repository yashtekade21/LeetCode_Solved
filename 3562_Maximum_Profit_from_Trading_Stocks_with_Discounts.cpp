class Solution {
public:
    int maxProfit(int n, vector<int>& present, vector<int>& future,
                  vector<vector<int>>& hierarchy, int budget) {
        int ans = 0;
        unordered_map<int, vector<int>> adj;

        for (auto& h : hierarchy) {
            int boss = h[0] - 1;
            int employee = h[1] - 1;
            adj[boss].push_back(employee);
        }

        // stateProfit[u][0][2] - profit at u where parent haven't buyed(0) when
        // budget was 2 stateProfit[u][1][2] - profit at u where parent have
        // buyed(1) when budget was 2
        vector<vector<vector<int>>> stateProfit(
            n, vector<vector<int>>(2, vector<int>(budget + 1, 0)));

        dfs(0, adj, present, future, budget, stateProfit);

        for (int b = 0; b <= budget; b++)
            ans = max(ans, stateProfit[0][0][b]);

        return ans;
    }

private:
    void dfs(int u, unordered_map<int, vector<int>>& adj, vector<int>& present,
             vector<int>& future, int budget,
             vector<vector<vector<int>>>& stateProfit) {
        vector<pair<vector<int>, vector<int>>> childStateProfit;

        for (auto& c : adj[u]) {
            dfs(c, adj, present, future, budget, stateProfit);
            childStateProfit.push_back({stateProfit[c][0], stateProfit[c][1]});
        }

        for (int parentBuy = 0; parentBuy <= 1; parentBuy++) {
            int price = (parentBuy == 1) ? present[u] / 2 : present[u];
            int profit = future[u] - price;

            vector<int> bestProfit(budget + 1, 0);

            vector<int> maxProfitNotBuyParent(budget + 1, 0);

            for (auto& child : childStateProfit) {
                vector<int> temp(budget + 1, 0);
                for (int used = 0; used <= budget; used++) {
                    for (int take = 0; used + take <= budget; take++) {
                        temp[used + take] =
                            max(temp[used + take], maxProfitNotBuyParent[used] +
                                                       child.first[take]);
                    }
                }
                maxProfitNotBuyParent = move(temp);
            }

            for (int b = 0; b <= budget; b++)
                bestProfit[b] = max(bestProfit[b], maxProfitNotBuyParent[b]);

            if (price <= budget) {
                vector<int> maxProfitBuyParent(budget + 1, 0);

                for (auto& child : childStateProfit) {
                    vector<int> temp(budget + 1, 0);
                    for (int used = 0; used <= budget; used++) {
                        for (int take = 0; used + take <= budget; take++) {
                            temp[used + take] = max(temp[used + take],
                                                    maxProfitBuyParent[used] +
                                                        child.second[take]);
                        }
                    }
                    maxProfitBuyParent = move(temp);
                }

                for (int b = price; b <= budget; b++)
                    bestProfit[b] = max(bestProfit[b],
                                        maxProfitBuyParent[b - price] + profit);
            }

            stateProfit[u][parentBuy] = move(bestProfit);
        }
    }
};
static const auto kds = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();
