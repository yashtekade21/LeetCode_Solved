class Solution {
public:
    vector<int> minimumCost(int n, vector<vector<int>>& edges,
                            vector<vector<int>>& query) {
        vector<int> parentNode, graphCost;

        for (int i = 0; i < n; i++) {
            parentNode.emplace_back(i);
            graphCost.emplace_back(-1);
        }

        for (auto& e : edges) {
            int u = e[0], v = e[1], w = e[2];
            int parent_u = DSUFind(u, parentNode);
            int parent_v = DSUFind(v, parentNode);

            if (parent_u != parent_v) {
                DSUUnion(parent_u, parent_v, parentNode);
                graphCost[parent_u] = (graphCost[parent_u] & graphCost[parent_v]);
            }

            graphCost[parent_u] = (graphCost[parent_u] & w);
        }

        vector<int> ans;
        for (auto& q : query) {
            int u = q[0], v = q[1];
            // int parent_u = parentNode[u], parent_v = parentNode[v];
            int parent_u = DSUFind(u, parentNode),
                parent_v = DSUFind(v, parentNode);

            if (u == v)
                ans.emplace_back(0);
            else if (parent_u != parent_v)
                ans.emplace_back(-1);
            else
                ans.emplace_back(graphCost[parent_u]);
        }

        return ans;
    }

private:
    int DSUFind(int node, vector<int>& parentNode) {
        if (parentNode[node] == node)
            return node;

        return parentNode[node] = DSUFind(parentNode[node], parentNode);
    }

    void DSUUnion(int parent, int node, vector<int>& parentNode) {
        parentNode[node] = parent;
    }
};
static const auto kds = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();
