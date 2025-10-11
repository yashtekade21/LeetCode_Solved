class Solution {
public:
    vector<long long> dp;
    int n;
    long long maximumTotalDamage(vector<int>& power) {

        unordered_map<long long, long long> mp;
        for (auto& spell : power)
            mp[spell]++;

        vector<long long> spells;
        for (auto& it : mp)
            spells.push_back(it.first);

        n = spells.size();
        sort(spells.begin(), spells.end());
        dp.resize(n, -1);

        return solve(spells, 0, mp);
    }

private:
    long long solve(vector<long long>& spells, int idx,
                    unordered_map<long long, long long>& mp) {
        if (idx > n - 1)
            return 0;

        if (dp[idx] != -1)
            return dp[idx];
        int j = lower_bound(spells.begin() + idx + 1, spells.end(),
                            spells[idx] + 3) -
                spells.begin();

        long long take = spells[idx] * mp[spells[idx]] + solve(spells, j, mp);
        long long notTake = solve(spells, idx + 1, mp);

        return dp[idx] = max(take, notTake);
    }
};class Solution {
public:
    vector<long long> dp;
    int n;
    long long maximumTotalDamage(vector<int>& power) {

        unordered_map<long long, long long> mp;
        for (auto& spell : power)
            mp[spell]++;

        vector<long long> spells;
        for (auto& it : mp)
            spells.push_back(it.first);

        n = spells.size();
        sort(spells.begin(), spells.end());
        dp.resize(n, -1);

        return solve(spells, 0, mp);
    }

private:
    long long solve(vector<long long>& spells, int idx,
                    unordered_map<long long, long long>& mp) {
        if (idx > n - 1)
            return 0;

        if (dp[idx] != -1)
            return dp[idx];
        int j = lower_bound(spells.begin() + idx + 1, spells.end(),
                            spells[idx] + 3) -
                spells.begin();

        long long take = spells[idx] * mp[spells[idx]] + solve(spells, j, mp);
        long long notTake = solve(spells, idx + 1, mp);

        return dp[idx] = max(take, notTake);
    }
};
static const auto kds = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();
