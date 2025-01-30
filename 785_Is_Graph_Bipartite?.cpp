class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> colored(n, -1);

        // red = 1 green = 0;

        for (int i = 0; i < n; i++) {
            if (colored[i] == -1 && !bfs_bipartite(graph, colored, i, 1))
                return false;
        }
        return true;
    }

private:
    bool bfs_bipartite(vector<vector<int>>& graph, vector<int>& colored,
                       int node, int cur_color) {
        queue<int> q;
        q.push(node);
        colored[node] = cur_color;

        while (!q.empty()) {
            int top = q.front();
            q.pop();

            for (auto& nei : graph[top]) {
                if (colored[nei] == colored[top])
                    return false;
                else if (colored[nei] == -1) {
                    colored[nei] = 1 - colored[top];
                    q.push(nei);
                }
            }
        }
        return true;
    }
};
static const auto kds = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();
