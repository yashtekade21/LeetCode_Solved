class Solution {
public:
    vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
        unordered_map<int, vector<int>> mp;
        vector<int> ans;
        int n = nums.size();
        for (int i = 0; i < n; i++)
            mp[nums[i]].emplace_back(i);

        for (auto& query : queries) {
            int num = nums[query];
            vector<int>& vec = mp[num];
            int vecSize = vec.size();

            if (vec.size() == 1) {
                ans.push_back(-1);
                continue;
            }

            int idx = lower_bound(vec.begin(), vec.end(), query) - vec.begin();
            int minD = INT_MAX;
            int rightIdx = vec[(idx + 1) % vecSize];
            int rd = abs(rightIdx - query);
            int rcd = n - rd;

            minD = min({minD, rd, rcd});

            int leftIdx = vec[(idx - 1 + vecSize) % vecSize];
            int ld = abs(leftIdx - query);
            int lcd = n - ld;

            minD = min({minD, ld, lcd});

            ans.push_back(minD);
        }

        return ans;
    }
};
static const auto kds = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();
