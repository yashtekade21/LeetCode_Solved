class Solution {
public:
    int maxKDivisibleComponents(int n, vector<vector<int>>& edges,
                                vector<int>& values, int k) {
        vector<vector<int>> adj(n);
        for (auto l : edges) {
            adj[l[0]].emplace_back(l[1]);
            adj[l[1]].emplace_back(l[0]);
        }

        int ans = 0;
        dfs(0, -1, ans, values, adj, k);
        return ans;
    }

private:
    int dfs(int cur, int parent, int& ans, vector<int>& values,
            vector<vector<int>>& adj, int& k) {
        int total_sum = values[cur];

        for (auto child : adj[cur]) {
            if (child != parent)
                total_sum += dfs(child, cur, ans, values, adj, k);
        }

        total_sum = total_sum%k;
        if(total_sum == 0)
            ans++;

        return total_sum;
    }
};
static const auto kds = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();
