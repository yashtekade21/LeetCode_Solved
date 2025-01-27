class Solution {
public:
    vector<bool> checkIfPrerequisite(int numCourses,
                                     vector<vector<int>>& prerequisites,
                                     vector<vector<int>>& queries) {
        unordered_map<int, vector<int>> graph;

        for (auto& node : prerequisites) {
            int u = node[0];
            int v = node[1];

            graph[u].emplace_back(v);
        }

        vector<vector<bool>> mapping(numCourses,
                                     vector<bool>(numCourses, false));
        check_prerequisites(graph, numCourses, mapping);

        vector<bool> result(queries.size());
        for (int i = 0; i < queries.size(); i++) {
            int u = queries[i][0];
            int v = queries[i][1];

            result[i] = mapping[u][v];
        }
        return result;
    }

private:
    void check_prerequisites(unordered_map<int, vector<int>>& graph,
                             int numCourses, vector<vector<bool>>& mapping) {
        for (int u = 0; u < numCourses; u++) {
            for (int v = 0; v < numCourses; v++) {
                if(u != v)
                    mapping[u][v] = bfs(graph, u, v, numCourses);
            }
        }
        return;
    }
    bool bfs(unordered_map<int, vector<int>>& graph, int u, int v,
             int numCourses) {
        vector<bool> vis(numCourses, false);

        queue<int> q;
        q.push(u);
        vis[u] = true;

        while (!q.empty()) {
            int top = q.front();
            q.pop();

            if (top == v)
                return true;

            for (auto& node : graph[top]) {
                if (!vis[node]) {
                    q.push(node);
                    vis[node] = true;
                }
            }
        }
        return false;
    }
};
static const auto kds = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();
