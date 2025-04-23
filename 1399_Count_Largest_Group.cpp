class Solution {
public:
    int countLargestGroup(int n) {
        unordered_map<int, int> mp;
        int maxSize = 0;
        for (int num = 1; num <= n; num++) {
            int temp = num;
            int sum = 0;
            while (temp != 0) {
                int rem = temp % 10;
                sum += rem;
                temp /= 10;
            }
            mp[sum]++;
            maxSize = max(mp[sum], maxSize);
        }

        int ans = 0;
        for (auto [sum, size] : mp) {
            // cout<<"sum = "<<sum<<" size = "<<size<<endl;
            if (size == maxSize)
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
