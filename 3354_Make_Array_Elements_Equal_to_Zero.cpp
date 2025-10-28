class Solution {
public:
    int countValidSelections(vector<int>& nums) {
        int n = nums.size();
        int possible = 0;

        for (int curr = 0; curr < n; curr++) {
            if (nums[curr] == 0) {
                if (check(nums, curr, -1))
                    possible++;

                if (check(nums, curr, 1))
                    possible++;
            }
        }
        return possible;
    }

private:
    bool check(vector<int> nums, int curr, int dir) {
        int n = nums.size();

        while (curr >= 0 && curr < n) {
            if (nums[curr] == 0)
                curr += dir;
            else {
                nums[curr]--;
                dir *= -1;
                curr += dir;
            }
        }

        for (auto i : nums) {
            if (i == 0)
                continue;
            else
                return 0;
        }
        return 1;
    }
};
static const auto kds = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();
