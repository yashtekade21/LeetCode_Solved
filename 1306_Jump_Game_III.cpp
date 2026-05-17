class Solution {
public:
    int n;
    bool canReach(vector<int>& arr, int start) {
        n = arr.size();
        vector<bool> vis(n, false);
        return solve(arr, start, vis);
    }

private:
    bool solve(vector<int>& arr, int idx, vector<bool>& vis) {
        if (idx < 0 || idx > n - 1 || vis[idx])
            return false;

        if (arr[idx] == 0)
            return true;

        vis[idx] = true;

        bool r = solve(arr, idx + arr[idx], vis);
        bool l = solve(arr, idx - arr[idx], vis);

        return r || l;
    }
};
static const auto kds = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();
