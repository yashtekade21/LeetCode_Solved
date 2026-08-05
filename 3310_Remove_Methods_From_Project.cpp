class Solution {
public:
    vector<int> remainingMethods(int n, int k,
                                 vector<vector<int>>& invocations) {
        vector<vector<int>> adj(n);
        vector<int> inDegree(n, 0);
        vector<bool> suspicious(n, false);

        for (auto& edge : invocations) {
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
            inDegree[v]++;
        }

        queue<int> q;
        q.push(k);
        suspicious[k] = true;

        while (!q.empty()) {
            int curr = q.front();
            q.pop();

            for (int& ngbr : adj[curr]) {
                inDegree[ngbr]--;
                if (!suspicious[ngbr]) {
                    q.push(ngbr);
                    suspicious[ngbr] = true;
                }
            }
        }

        vector<int> ans;
        bool cannotRemove = false;

        for (int i = 0; i < n; i++) {
            if (suspicious[i] && inDegree[i] > 0) {
                cannotRemove = true;
                break;
            }

            if (!suspicious[i])
                ans.push_back(i);
        }

        if (cannotRemove) {
            vector<int> v(n);
            for (int i = 0; i < n; i++)
                v[i] = i;

            return v;
        }

        return ans;
    }
};
static const auto kds = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();
