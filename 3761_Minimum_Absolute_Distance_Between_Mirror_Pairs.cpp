class Solution {
public:
    int minMirrorPairDistance(vector<int>& nums) {
        int ans = INT_MAX;
        int n = nums.size();
        unordered_map<int, int> mp;
        for (int i = 0; i < n; i++) {
            if (mp.count(nums[i]))
                ans = min(ans, i - mp[nums[i]]);

            mp[reverse(nums[i])] = i;
        }

        return ans == INT_MAX ? -1 : ans;
    }

private:
    int reverse(int num) {
        int revNum = 0;
        while (num > 0) {
            revNum = (revNum * 10) + num % 10;
            num /= 10;
        }
        return revNum;
    }
};
static const auto kds = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();
