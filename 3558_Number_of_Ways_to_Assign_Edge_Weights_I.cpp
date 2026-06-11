class Solution {
public:
    long long MOD = 1e9 + 7;
    int assignEdgeWeights(vector<vector<int>>& edges) {

        unordered_map<int, vector<int>> adj;

        for (auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        int maxDepth = getMaxDepth(adj, 1, 0);

        return power(2, maxDepth - 1);
    }

private:
    long long power(long long base, long long exponent) {
        if (exponent == 0)
            return 1;

        long long half = power(base, exponent / 2);

        long long result = (half * half) % MOD;

        if (exponent % 2 == 1) {
            result = (result * base) % MOD;
        }

        return result;
    }

    int getMaxDepth(unordered_map<int, vector<int>>& adj, int node,
                    int parent) {

        int ans = 0;

        for (int neighbor : adj[node]) {
            if (neighbor == parent)
                continue;

            ans = max(ans, getMaxDepth(adj, neighbor, node) + 1);
        }

        return ans;
    }
};
static const auto kds = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();
