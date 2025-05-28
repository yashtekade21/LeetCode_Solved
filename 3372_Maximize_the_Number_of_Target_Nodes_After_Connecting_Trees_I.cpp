class Solution {
public:
    vector<int> maxTargetNodes(vector<vector<int>>& edges1,
                               vector<vector<int>>& edges2, int k) {
        vector<int> tree1 = calcTargetNodes(edges1, k);
        vector<int> tree2 = calcTargetNodes(edges2, k - 1);

        int maxTargetNodesTree2 = *max_element(tree2.begin(), tree2.end());

        for (int i = 0; i < tree1.size(); i++)
            tree1[i] += maxTargetNodesTree2;

        return tree1;
    }

private:
    vector<int> calcTargetNodes(vector<vector<int>>& edges, int k) {
        unordered_map<int, vector<int>> adj;
        for (auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];

            adj[u].emplace_back(v);
            adj[v].emplace_back(u);
        }

        int n = edges.size() + 1;
        vector<int> targetNodes(n);
        for (int i = 0; i < n; i++) 
            targetNodes[i] = bfs(i, adj, k, n);
        
        return targetNodes;
    }

    int bfs(int node, unordered_map<int, vector<int>>& adj, int d, int n) {
        queue<pair<int, int>> q;
        vector<bool> vis(n, false);
        q.push({node, 0});
        vis[node] = true;

        int cntTargetNodes = 0;
        while (!q.empty()) {
            auto top = q.front();
            int curNode = top.first;
            int dist = top.second;
            q.pop();

            if (dist > d)
                continue;
            cntTargetNodes++;

            for (auto& nbr : adj[curNode]) {
                if (!vis[nbr]) {
                    q.push({nbr, dist + 1});
                    vis[nbr] = true;
                }
            }
        }
        return cntTargetNodes;
    }
};
static const auto kds = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();
