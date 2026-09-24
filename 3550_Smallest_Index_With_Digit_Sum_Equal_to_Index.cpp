class Solution {
public:
    int smallestIndex(vector<int>& nums) {
        for (int i = 0; i < nums.size(); i++) {
            if (solve(nums[i]) == i)
                return i;
        }
        return -1;
    }

private:
    int solve(int num) {
        int sum = 0;
        while (num != 0) {
            int rem = num % 10;
            sum += rem;
            num /= 10;
        }
        return sum;
    }
};
static const auto kds = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();
