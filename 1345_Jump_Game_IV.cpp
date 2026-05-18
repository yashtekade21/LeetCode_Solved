class Solution {
public:
    int n;
    int minJumps(vector<int>& arr) {
        n = arr.size();
        unordered_map<int, vector<int>> mp;
        vector<bool> vis(n, false);

        for (int i = 0; i < n; i++)
            mp[arr[i]].push_back(i);

        return bfs(arr, 0, mp, vis);
    }

private:
    int bfs(vector<int>& arr, int i, unordered_map<int, vector<int>>& mp,
            vector<bool>& vis) {

        int steps = 0;

        queue<int> q;
        q.push(0);
        vis[0] = true;

        while (!q.empty()) {
            int s = q.size();

            while (s--) {
                int curr = q.front();
                q.pop();
                int l = curr - 1, r = curr + 1;

                if (curr == n - 1)
                    return steps;

                if (l >= 0 && !vis[l]) {
                    q.push(l);
                    vis[l] = true;
                }
                if (r <= n - 1 && !vis[r]) {
                    q.push(r);
                    vis[r] = true;
                }

                for (auto& idx : mp[arr[curr]]) {
                    if (!vis[idx]) {
                        q.push(idx);
                        vis[idx] = true;
                    }
                }

                mp.erase(arr[curr]);
            }
            steps++;
        }
        return -1;
    }
};
static const auto kds = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();
