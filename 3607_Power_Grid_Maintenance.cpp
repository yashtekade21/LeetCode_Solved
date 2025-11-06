class Solution {
public:
    vector<int> processQueries(int c, vector<vector<int>>& connections,
                               vector<vector<int>>& queries) {
        unordered_map<int, vector<int>> adj;

        for (auto& edge : connections) {
            int u = edge[0], v = edge[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<bool> vis(c + 1, false);
        vector<int> groupId(c + 1);
        unordered_map<int, set<int>> mp;

        for (int i = 1; i <= c; i++) {
            if (!vis[i]) {
                int grpId = i;
                dfs(i, adj, vis, grpId, groupId, mp);
            }
        }

        vector<int> ans;
        for (auto& query : queries) {
            int qType = query[0];
            int station = query[1];

            int grpId = groupId[station];
            if (qType == 1) {
                if (mp[grpId].find(station) != mp[grpId].end())
                    ans.push_back(station);
                else if (!mp[grpId].empty())
                    ans.push_back(*mp[grpId].begin());
                else
                    ans.push_back(-1);
            } else
                mp[grpId].erase(station);
        }
        return ans;
    }

private:
    void dfs(int station, unordered_map<int, vector<int>>& adj,
             vector<bool>& vis, int grpId, vector<int>& groupId,
             unordered_map<int, set<int>>& mp) {
        vis[station] = true;
        mp[grpId].insert(station);
        groupId[station] = grpId;

        for (auto& ngbr : adj[station]) {
            if (!vis[ngbr])
                dfs(ngbr, adj, vis, grpId, groupId, mp);
        }
    }
};
static const auto kds = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();
