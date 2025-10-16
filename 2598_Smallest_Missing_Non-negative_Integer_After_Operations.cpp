class Solution {
public:
    int findSmallestInteger(vector<int>& nums, int value) {
        unordered_map<int, int> mp;

        for (int i = 0; i < nums.size(); i++) {
            int rem;
            if (nums[i] < 0)
                rem = ((nums[i] % value) + value) % value;
            else
                rem = nums[i] % value;

            mp[rem]++;
        }

        int ans = 0;
        while (true) {
            if (mp[ans % value] != 0)
                mp[ans % value]--;
            else
                break;
            ans++;
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
