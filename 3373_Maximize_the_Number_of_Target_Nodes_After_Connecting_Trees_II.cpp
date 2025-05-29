class Solution {
public:
    vector<int> maxTargetNodes(vector<vector<int>>& edges1,
                               vector<vector<int>>& edges2) {
        unordered_map<int, vector<int>> tree1 = calcAdj(edges1);
        unordered_map<int, vector<int>> tree2 = calcAdj(edges2);

        int n = edges1.size();
        vector<int> markTree1(n + 1, -1);
        markTree1[0] = 0;
        int cntEvenTree1 = 0, cntOddTree1 = 0;
        dfs(0, tree1, -1, markTree1, cntEvenTree1, cntOddTree1);

        int m = edges2.size();
        vector<int> markTree2(m + 1, -1);
        markTree2[0] = 0;
        int cntEvenTree2 = 0, cntOddTree2 = 0;
        dfs(0, tree2, -1, markTree2, cntEvenTree2, cntOddTree2);

        int maxDistTree2 = max(cntEvenTree2, cntOddTree2);

        vector<int> ans(n + 1);
        for (int i = 0; i <= n; i++)
            ans[i] = (markTree1[i] == 0 ? cntEvenTree1 : cntOddTree1) + maxDistTree2;

        return ans;
    }

private:
    unordered_map<int, vector<int>> calcAdj(vector<vector<int>>& edges) {
        unordered_map<int, vector<int>> adj;
        for (auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];

            adj[u].emplace_back(v);
            adj[v].emplace_back(u);
        }

        return adj;
    }

    void dfs(int node, unordered_map<int, vector<int>>& adj, int parent,
             vector<int>& mark, int& evenCnt, int& oddCnt) {

        if (mark[node] == 0)
            evenCnt++;
        else
            oddCnt++;

        for (auto& nbr : adj[node]) {
            if (nbr != parent) {
                mark[nbr] = (mark[node] == 0) ? 1 : 0;
                dfs(nbr, adj, node, mark, evenCnt, oddCnt);
            }
        }
    }
};
static const auto kds = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();
