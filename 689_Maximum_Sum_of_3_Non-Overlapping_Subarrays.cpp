class Solution {
public:
    vector<vector<int>> dp;
    Solution() : dp(20001,vector<int>(4,-1)){};
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> subarr;
        subarr_sum(subarr, nums, k);

        vector<int> ans;
        solve(subarr, k, 0, 0, ans);
        return ans;
    }

private:
    // subarr - cumulative sum of subarrays & cnt - max 3 subarrays & i - index
    // in nums & ans - index of 3 subarray;
    void solve(vector<int>& subarr, int k, int cnt, int i, vector<int>& ans) {
        if (cnt == 3)
            return;
        if (i > subarr.size() - 1)
            return;

        int add_i = subarr[i] + total_subarrs_sum(subarr, cnt + 1, i + k, k);
        int not_add_i = total_subarrs_sum(subarr, cnt, i + 1, k);

        if (add_i >= not_add_i) {
            ans.emplace_back(i);
            solve(subarr, k, cnt + 1, i + k, ans);
        } else
            solve(subarr, k, cnt, i + 1, ans);

        return;
    }

    int total_subarrs_sum(vector<int>& subarr, int cnt, int i, int k) {
        if (cnt == 3)
            return 0;
        if (i > subarr.size() - 1)
            return INT_MIN;

        if(dp[i][cnt] != -1)
            return dp[i][cnt];

        int add = subarr[i] + total_subarrs_sum(subarr, cnt + 1, i + k, k);
        int not_add = total_subarrs_sum(subarr, cnt, i + 1, k);

        return dp[i][cnt] = max(add, not_add);
    }


    void subarr_sum(vector<int>& subarr, vector<int>& nums, int k) {
        int i = 0;
        long long cur_sum = 0;

        for (int j = 0; j < nums.size(); j++) {
            cur_sum += nums[j];
            if (j - i + 1 == k) {
                subarr.emplace_back(cur_sum);
                cur_sum -= nums[i];
                i++;
            }
        }
        return;
    }
};
static const auto kds = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();
