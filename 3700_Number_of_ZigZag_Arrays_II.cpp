class Solution {
public:
    const int MOD = 1e9 + 7;
    int zigZagArrays(int n, int l, int r) {
        int m = r - l + 1;
        int S = 2 * m;

        auto U = [&](int v) { return v - 1; };

        auto D = [&](int v) { return m + (v - 1); };

        vector<vector<long long>> T(S, vector<long long>(S, 0));

        for (int v = 1; v <= m; v++) {
            for (int u = 1; u < v; u++) {
                T[U(v)][D(u)] = 1;
            }
            for (int u = v + 1; u <= m; u++) {
                T[D(v)][U(u)] = 1;
            }
        }

        vector<long long> dp2(S, 0);

        for (int v = 1; v <= m; v++) {
            dp2[U(v)] = v - 1;
            dp2[D(v)] = m - v;
        }

        vector<vector<long long>> P = power(T, n - 2);

        vector<long long> dpn(S, 0);

        for (int i = 0; i < S; i++) {
            for (int j = 0; j < S; j++) {
                dpn[i] = (dpn[i] + P[i][j] * dp2[j]) % MOD;
            }
        }

        long long ans = 0;

        for (long long x : dpn)
            ans = (ans + x) % MOD;

        return ans;
    }

private:
    vector<vector<long long>> multiply(vector<vector<long long>>& arr1,
                                       vector<vector<long long>>& arr2) {
        int n = arr1.size();

        vector<vector<long long>> arr3(n, vector<long long>(n, 0));

        for (int i = 0; i < n; i++) {
            for (int k = 0; k < n; k++) {
                if (arr1[i][k] == 0) {
                    continue;
                }

                for (int j = 0; j < n; j++) {

                    if (arr2[k][j] == 0) {
                        continue;
                    }
                    arr3[i][j] = (arr3[i][j] % MOD +
                                  (arr1[i][k] % MOD * arr2[k][j] % MOD) % MOD) %
                                 MOD;
                }
            }
        }

        return arr3;
    }

    vector<vector<long long>> power(vector<vector<long long>> base,
                                    long long exp) {
        int n = base.size();

        vector<vector<long long>> result(n, vector<long long>(n, 0));

        for (int i = 0; i < n; i++)
            result[i][i] = 1;

        while (exp) {
            if (exp & 1) {
                result = multiply(result, base);
            }
            base = multiply(base, base);
            exp >>= 1;
        }

        return result;
    }
};
static const auto kds = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();
