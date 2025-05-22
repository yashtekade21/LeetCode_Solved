class Solution {
public:
    int maxRemoval(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        int q = queries.size();

        sort(queries.begin(), queries.end());
        priority_queue<int> maxIdx;
        priority_queue<int, vector<int>, greater<int>> pastIdx;

        int j = 0, ans = 0;

        for (int i = 0; i < n; i++) {
            while (j < q && queries[j][0] == i) {
                maxIdx.push(queries[j][1]);
                j++;
            }

            nums[i] -= pastIdx.size();

            while (nums[i] > 0 && !maxIdx.empty() && maxIdx.top() >= i) {
                int lastIdx = maxIdx.top();
                maxIdx.pop();
                pastIdx.push(lastIdx);
                ans++;
                nums[i]--;
            }

            if (nums[i] > 0)
                return -1;

            while (!pastIdx.empty() && pastIdx.top() <= i)
                pastIdx.pop();
        }
        return q - ans;
    }
};
static const auto kds = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();
