class Solution {
public:
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        int n = edges.size() + 1;

        vector<int> dist1(n, INT_MAX), dist2(n, INT_MAX);
        dist1[node1] = 0;
        dist2[node2] = 0;

        vector<bool> vis1(n, false);
        vector<bool> vis2(n, false);

        dfs(node1, edges, vis1, dist1);
        dfs(node2, edges, vis2, dist2);

        int maxDist = 0, minDistAll = INT_MAX, minIdx = -1;
        for (int i = 0; i < n; i++) {
            maxDist = max(dist1[i], dist2[i]);

            if (minDistAll > maxDist) {
                minDistAll = maxDist;
                minIdx = i;
            }
        }
        return minIdx;
    }

private:
    void dfs(int node, vector<int>& edges, vector<bool>& vis,
             vector<int>& dist) {
        vis[node] = true;

        int nxtNode = edges[node];
        if (nxtNode != -1 && !vis[nxtNode]) {
            vis[nxtNode] = true;
            dist[nxtNode] = dist[node] + 1;
            dfs(nxtNode, edges, vis, dist);
        }
    }
};
static const auto kds = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();
