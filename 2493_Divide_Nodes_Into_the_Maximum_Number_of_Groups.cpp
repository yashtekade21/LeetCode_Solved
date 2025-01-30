class Solution {
public:
    int magnificentSets(int n, vector<vector<int>>& edges) {
        unordered_map<int, vector<int>> graph;

        for (auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];

            graph[u].emplace_back(v);
            graph[v].emplace_back(u);
        }

        // Check Bipartite first
        vector<int> colored(n + 1, -1);
        for (int i = 1; i <= n; i++) {
            if (colored[i] == -1 &&
                !bfs_bipartite(graph, colored, i, 1)) // red =1 && green = 0
                return -1;
        }

        // BFS for check max level possible
        vector<int> level(n+1, 0);
        for (int i = 1; i <= n; i++) {
            level[i] = bfs_level(graph, i, n);
        }

        // BFS max_group from each component
        int max_grp = 0;
        vector<bool> visited(n + 1, false);
        for (int i = 1; i <= n; i++) {
            if (!visited[i]) {
                max_grp += get_max_grps(graph, i, visited, level);
            }
        }
        return max_grp;
    }

private:
    bool bfs_bipartite(unordered_map<int, vector<int>>& graph,
                       vector<int>& colored, int node, int cur_color) {
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

    int bfs_level(unordered_map<int, vector<int>>& graph, int node, int n) {
        vector<bool> vis(n + 1, false);

        queue<int> q;
        q.push(node);
        vis[node] = true;
        int level = 0;
        while (!q.empty()) {
            int q_size = q.size();

            while (q_size--) {
                int top = q.front();
                q.pop();

                for (auto& nei : graph[top]) {
                    if (!vis[nei]) {
                        q.push(nei);
                        vis[nei] = true;
                    }
                }
            }
            level++;
        }
        return level;
    }

    int get_max_grps(unordered_map<int, vector<int>>& graph, int node,vector<bool>& visited,vector<int>& level){
        int max_grp = level[node];

        queue<int> q;
        q.push(node);
        visited[node] = true;

        while(!q.empty()){
            int top = q.front();
            q.pop();

            for(auto& nei:graph[top]){
                if(!visited[nei]){
                    max_grp = max(max_grp,level[nei]);
                    q.push(nei);
                    visited[nei] = true;
                }
            }
        }
        return max_grp;
    }
};
static const auto kds = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();
