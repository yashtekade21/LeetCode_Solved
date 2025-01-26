class Solution {
public:
    int maximumInvitations(vector<int>& favorite) {
        int n = favorite.size();
        unordered_map<int, vector<int>> rev_fav;

        for (int i = 0; i < n; i++) {
            int u = i;
            int v = favorite[i];
            // u --> v

            rev_fav[v].emplace_back(u);
            // v --> u
        }

        int max_cycle = 0;
        int two_cycle = 0;

        vector<bool> vis(n, false);

        for (int i = 0; i < n; i++) {

            if (!vis[i]) {
                unordered_map<int, int>
                    mp; // stores count of nodes seen till now

                int cur_node = i;
                int cur_cnt = 0;

                while (!vis[cur_node]) {
                    vis[cur_node] = true;
                    mp[cur_node] = cur_cnt;

                    int next_node = favorite[cur_node];
                    cur_cnt++;

                    if (mp.count(next_node)) {
                        int cycle_length = cur_cnt - mp[next_node];
                        max_cycle = max(max_cycle, cycle_length);

                        if (cycle_length == 2) {
                            vector<bool> visBFS(n, false);
                            visBFS[cur_node] = visBFS[next_node] = true;
                            two_cycle += 2 + BFS(cur_node, rev_fav, visBFS) +
                                         BFS(next_node, rev_fav, visBFS);
                        }
                        break;
                    }
                    cur_node = next_node;
                }
            }
        }
        return max(two_cycle, max_cycle);
    }

private:
    int BFS(int node, unordered_map<int, vector<int>>& fav, vector<bool>& vis) {
        queue<pair<int, int>> q; // node, path_length

        q.push({node, 0});

        int max_path = 0;

        while (!q.empty()) {
            auto [cur_node, len] = q.front();
            q.pop();

            for (auto& nei : fav[cur_node]) {
                if (!vis[nei]) {
                    vis[nei] = true;

                    q.push({nei, len + 1});
                    max_path = max(max_path, len + 1);
                }
            }
        }
        return max_path;
    }
};
static const auto kds = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();
