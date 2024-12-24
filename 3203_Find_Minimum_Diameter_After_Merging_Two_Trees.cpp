class Solution {
public:
    int minimumDiameterAfterMerge(vector<vector<int>>& edges1,
                                  vector<vector<int>>& edges2) {
        unordered_map<int, vector<int>> g1 = create_graph(edges1),
                                        g2 = create_graph(edges2);

        int d1 = find_diameter(g1), d2 = find_diameter(g2);
        int merged_diameter = ceil(d1 / 2.0) + ceil(d2 / 2.0) + 1;

        return max(merged_diameter, max(d1, d2));
    }

private:
    unordered_map<int, vector<int>> create_graph(vector<vector<int>>& mat) {
        unordered_map<int, vector<int>> mp;
        for (auto i : mat){
            mp[i[0]].emplace_back(i[1]);
            mp[i[1]].emplace_back(i[0]);
        }
        return mp;
    }

    int find_diameter(unordered_map<int, vector<int>>& g) {
        // choose randomly one node and calculate farthest node from it. By law
        // the farthest node will be one end of diameter.
        auto [oneNode, dist] = BFS(g, 0);

        // calculate another farthest node from one Node i.e. other end of the
        // diameter. It will be your diameter length.
        auto [otherNode, diameter] = BFS(g, oneNode);

        return diameter;
    }

    pair<int, int> BFS(unordered_map<int, vector<int>>& g, int cur_node) {
        queue<int> q;
        q.push(cur_node);

        unordered_map<int, bool> visited;
        visited[cur_node] = true;
        int dist = 0, far_node = cur_node;

        while (!q.empty()) {
            int n = q.size();
            while (n--) {
                int top = q.front();
                q.pop();

                far_node = top;

                for (auto& nei : g[top]) {
                    if (!visited[nei]) {
                        q.push(nei);
                        visited[nei] = true;
                    }
                }
            }
            if (!q.empty())
                dist++;
        }
        return {far_node, dist};
    }
};
static const auto kds = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();
