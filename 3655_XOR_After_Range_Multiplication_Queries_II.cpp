class Solution {
public:
    const int MOD = 1e9 + 7;
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        int blockSize = ceil(sqrt(n));
        int ans = 0;

        unordered_map<int, vector<vector<int>>> smallKMap;

        for (auto& query : queries) {
            int l = query[0];
            int r = query[1];
            int k = query[2];
            int v = query[3];

            if (k >= blockSize) {
                for (int i = l; i <= r; i += k)
                    nums[i] = (1LL * nums[i] * v) % MOD;

            } else
                smallKMap[k].push_back(query);
        }

        for (auto& [k, allQueries] : smallKMap) {
            vector<long long> diff(n, 1);

            for (auto& query : allQueries) {
                int l = query[0];
                int r = query[1];
                int v = query[3];

                diff[l] = (diff[l] * v) % MOD;

                int steps = (r - l) / k;
                int next = l + (steps + 1) * k;

                if (next < n)
                    diff[next] = (diff[next] * power(v, MOD - 2)) % MOD;
            }

            for (int i = 0; i < n; i++) {
                if (i - k >= 0)
                    diff[i] = (diff[i] * diff[i - k]) % MOD;
            }

            for (int i = 0; i < n; i++)
                nums[i] = (1LL * nums[i] * diff[i]) % MOD;
        }

        for (int& num : nums)
            ans = (ans ^ num);

        return ans;
    }

private:
    long long power(long long base, long long exp) {
        if (exp == 0)
            return 1;

        long long half = power(base, exp / 2);
        long long ans = (half * half) % MOD;

        if (exp % 2 == 1)
            ans = (ans * base) % MOD;

        return ans;
    }
};
static const auto kds = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();
