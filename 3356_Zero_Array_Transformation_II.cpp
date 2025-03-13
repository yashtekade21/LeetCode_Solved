class Solution {
public:
    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        int q = queries.size();

        int cnt0 = count(nums.begin(), nums.end(), 0);
        if (cnt0 == n)
            return 0;

        int l = 0, r = q - 1;
        int countQueries = -1;
        ;
        while (l <= r) {
            int mid = (r + l) / 2;
            if (updateByDiffArr(nums, queries, mid)) {
                countQueries = mid + 1;
                r = mid - 1;
            } else
                l = mid + 1;
        }
        return countQueries;
    }

private:
    bool updateByDiffArr(vector<int>& nums, vector<vector<int>>& queries,
                         int& k) {
        int n = nums.size();
        vector<int> diffArr(n, 0);

        for (int i = 0; i <= k; i++) {
            int s = queries[i][0];
            int e = queries[i][1];
            int val = queries[i][2];

            diffArr[s] += val;
            if (e + 1 < n)
                diffArr[e + 1] -= val;
        }

        int cumSum = 0;
        for (int i = 0; i < n; i++) {
            cumSum += diffArr[i];

            diffArr[i] = cumSum;

            if (nums[i] > diffArr[i])
                return false;
        }
        return true;
    }
};
static const auto kds = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();
