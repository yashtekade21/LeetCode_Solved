class Solution {
public:
    int splitArray(vector<int>& nums, int k) {
        int n = nums.size();
        if (k > n)
            return -1;

        int low = *max_element(nums.begin(), nums.end()),
            high = accumulate(nums.begin(), nums.end(), 0);

        while (low <= high) {
            int mid = (low + high) / 2;
            int sum = func(nums, n, mid);
            if (sum > k)
                low = mid + 1;
            else
                high = mid - 1;
        }
        return low;
    }

private:
    int func(vector<int>& nums, int n, int sum) {
        int k = 1;
        int tempSum = 0;
        for (int i = 0; i < n; i++) {
            if (tempSum + nums[i] <= sum)
                tempSum += nums[i];
            else {
                k++;
                tempSum = nums[i];
            }
        }
        return k;
    }
};
static const auto kds = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();
