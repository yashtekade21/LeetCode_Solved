class Solution {
public:
    long long minCost(vector<int>& basket1, vector<int>& basket2) {
        unordered_map<int, long long> mp;
        int minFruit = INT_MAX;

        for (auto& fruit : basket1) {
            mp[fruit]++;
            minFruit = min(minFruit, fruit);
        }

        for (auto& fruit : basket2) {
            mp[fruit]--;
            minFruit = min(minFruit, fruit);
        }

        vector<long long> basUnbalanced;

        for (auto& [fruit, freq] : mp) {
            if (freq == 0)
                continue;

            if (freq % 2 != 0)
                return -1;

            basUnbalanced.insert(basUnbalanced.end(), abs(freq) / 2, fruit);
        }

        sort(basUnbalanced.begin(), basUnbalanced.end());

        long long ans = 0;

        for (int i = 0; i < basUnbalanced.size() / 2; i++)
            ans += min((long long)basUnbalanced[i], (long long)minFruit * 2);

        return ans;
    }
};
static const auto kds = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();
