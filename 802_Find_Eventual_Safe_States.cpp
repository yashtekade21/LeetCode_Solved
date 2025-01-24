class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<vector<int>> new_graph(n);
        vector<int> indegree(n, 0);
        queue<int> q;

        for (int i = 0; i < n; i++) {
            for (auto& j : graph[i]) {
                new_graph[j].emplace_back(i);
                indegree[i]++;
            }
        }

        for (int i = 0; i < n; i++) {
            if (indegree[i] == 0)
                q.push(i);
        }

        vector<bool> safe(n, false);

        while (!q.empty()) {
            int x = q.front();
            q.pop();

            safe[x] = true;

            for (auto& e : new_graph[x]) {
                indegree[e]--;

                if (indegree[e] == 0)
                    q.push(e);
            }
        }
        vector<int> safenodes;
        for (int i = 0; i < n; i++) {
            if (safe[i])
                safenodes.emplace_back(i);
        }
        return safenodes;
    }
};
static const auto kds = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();
