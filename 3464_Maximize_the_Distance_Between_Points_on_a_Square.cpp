class Solution {
public:
    int maxDistance(int side, vector<vector<int>>& points, int k) {
        long long perimeter = 4LL * side;
        int ans = 0;
        int n = points.size();
        vector<long long> positions(n);

        for (int i = 0; i < n; i++)
            positions[i] = get1D(side, points[i][0], points[i][1]);

        sort(begin(positions), end(positions));
        vector<long long> doubled(2 * n);
        for (int i = 0; i < n; i++) {
            doubled[i] = positions[i];
            doubled[i + n] = positions[i] + perimeter;
        }

        int l = 0;
        int r = 2 * side;

        while (l <= r) {
            long long mid = l + (r - l) / 2;

            if (check(doubled, n, k, side, mid)) {
                ans = mid;
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }

        return ans;
    }

private:
    long long get1D(int side, int x, int y) {
        if (y == 0)
            return x;

        if (x == side)
            return side + y;

        if (y == side)
            return 3LL * side - x;

        return 4LL * side - y;
    }

    bool check(vector<long long>& doubled, int n, int k, int side, int mid) {
        long long perimeter = 4LL * side;

        for (int i = 0; i < n; i++) {
            int count = 1, idx = i;

            long long lastPos = doubled[idx];

            for (int j = 2; j <= k; j++) {
                long long target = lastPos + mid;

                auto it = lower_bound(begin(doubled) + idx + 1,
                                      begin(doubled) + i + n, target);

                if (it == begin(doubled) + i + n)
                    break;

                idx = it - begin(doubled);
                lastPos = doubled[idx];
                count++;
            }

            if (count == k && (doubled[i] + perimeter - lastPos >= mid))
                return true;
        }
        return false;
    }
};
static const auto kds = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();
