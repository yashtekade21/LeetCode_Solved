class Solution {
public:
    vector<int> applyOperations(vector<int>& nums) {
        int n = nums.size();

        for (int i = 0; i < n - 1; i++) {
            if (nums[i] == nums[i + 1]) {
                nums[i] = nums[i] * 2;
                nums[i + 1] = 0;
            }
        }
       
        queue<int> q;
        vector<int> result;

        for (int i = 0; i < n; i++) {
            if (nums[i] != 0)
                q.push(nums[i]);
        }

        while (!q.empty()) {
            int num = q.front();
            q.pop();
            result.emplace_back(num);
        }

        while (result.size() != n)
            result.emplace_back(0);

        return result;
    }
};
static const auto kds = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();
