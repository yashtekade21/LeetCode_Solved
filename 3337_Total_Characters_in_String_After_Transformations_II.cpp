class Solution {
public:
    const int MOD = 1e9 + 7;
    typedef vector<vector<long long>> V;

    int lengthAfterTransformations(string s, int t, vector<int>& nums) {
        int ans = 0;

        vector<int> mp(26, 0);
        for (auto& ch : s)
            mp[ch - 'a']++;

        V transform(26, vector<long long>(26, 0));
        for (int i = 0; i < 26; i++)
            for (int next = 1; next <= nums[i]; next++)
                transform[(i + next) % 26][i]++;

        V mat1 = matExp(transform, t);

        vector<int> updatedMp(26, 0);
        for (int i = 0; i < 26; ++i) {
            for (int j = 0; j < 26; ++j)
                updatedMp[i] =
                    (updatedMp[i] + (1LL * mat1[i][j] * mp[j]) % MOD) % MOD;
        }

        for (auto& cnt : updatedMp)
            ans = (ans + cnt) % MOD;

        return ans;
    }

private:
    V matExp(V& base, int exp) {
        if (exp == 0)
            return identityMatrix();

        V half = matExp(base, exp / 2);
        V result = matMul(half, half);

        if (exp % 2 == 0)
            return result;

        return matMul(result, base);
    }

    V identityMatrix() {
        V idMat(26, vector<long long>(26, 0));
        for (int i = 0; i < 26; i++)
            idMat[i][i] = 1;
        return idMat;
    }

    V matMul(V& v1, V& v2) {
        V result(26, vector<long long>(26, 0));
        for (int i = 0; i < 26; i++) {
            for (int j = 0; j < 26; j++) {
                for (int k = 0; k < 26; k++) {
                    result[i][j] =
                        (result[i][j] + (1LL * v1[i][k] * v2[k][j]) % MOD) %
                        MOD;
                }
            }
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
