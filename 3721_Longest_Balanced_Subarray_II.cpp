class Solution {
public:
    int n;
    vector<int> segMin, segMax, lazy;
    int longestBalanced(vector<int>& nums) {
        n = nums.size();
        segMin.assign(4 * n, 0);
        segMax.assign(4 * n, 0);
        lazy.assign(4 * n, 0);

        vector<int> prefSum(n, 0);
        unordered_map<int, int> mp;
        int ans = 0;

        for (int i = 0; i < n; i++) {
            int val = (nums[i] % 2 == 0) ? 1 : -1;

            int prev = -1;
            if (mp.find(nums[i]) != mp.end())
                prev = mp[nums[i]];

            if (prev != -1)
                updateRange(0, prev, 0, 0, n - 1, -val);

            updateRange(0, i, 0, 0, n - 1, val);

            int j = findBalSubArr(0, 0, n - 1);
            if (j != -1)
                ans = max(ans, i - j + 1);

            mp[nums[i]] = i;
        }
        return ans;
    }

private:
    void updateRange(int s, int e, int i, int l, int r, int val) {
        propogate(i, l, r);

        if (l > e || r < s)
            return;

        if (l >= s && r <= e) {
            lazy[i] += val;
            propogate(i, l, r);
            return;
        }

        int m = (l + r) / 2;
        updateRange(s, e, 2 * i + 1, l, m, val);
        updateRange(s, e, 2 * i + 2, m + 1, r, val);

        segMin[i] = min(segMin[2 * i + 1], segMin[2 * i + 2]);
        segMax[i] = max(segMax[2 * i + 1], segMax[2 * i + 2]);
    }

    void propogate(int i, int l, int r) {
        if (lazy[i] != 0) {
            segMin[i] += lazy[i];
            segMax[i] += lazy[i];

            if (l != r) {
                lazy[2 * i + 1] += lazy[i];
                lazy[2 * i + 2] += lazy[i];
            }
            lazy[i] = 0;
        }
    }

    int findBalSubArr(int i, int l, int r) {
        propogate(i, l, r);

        if (segMin[i] > 0 || segMax[i] < 0)
            return -1;

        if (l == r)
            return l;

        int m = (l + r) / 2;
        int left = findBalSubArr(2 * i + 1, l, m);
        if (left != -1)
            return left;

        int right = findBalSubArr(2 * i + 2, m + 1, r);
        return right;
    }
};
static const auto kds = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();
