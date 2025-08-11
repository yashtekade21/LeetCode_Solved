class Solution {
public:
    const int MOD = 1e9 + 7;
    vector<int> productQueries(int n, vector<vector<int>>& queries) {
        vector<int> ans;
        vector<int> powerArr;

        powerArr = calcPowerArr(n);


        for (auto& query : queries) {
            int s = query[0];
            int e = query[1];

            long prod = 1;

            for (int i = s; i <= e; i++)
                prod = (prod * powerArr[i]) % MOD;

            ans.emplace_back(prod);
        }
        return ans;
    }

private:
    vector<int> calcPowerArr(int n) {
        vector<int> arr;
        for (int i = 0; i < 32; i++) {
            if ((n & (1 << i)) != 0)
                arr.emplace_back(1 << i);
        }
        return arr;
    }
};
static const auto kds = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();
