class Solution {
public:
    int findTheLongestSubstring(string s) {
        int xor_val = 0;
        int ans = 0;
        unordered_map<int, int> mp;
        mp.insert({0, -1});

        for (int i = 0; i < s.length(); i++) {
            if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' ||
                s[i] == 'u')
                xor_val = xor_val ^ s[i];

            if (mp.find(xor_val) != mp.end())
                ans = max(ans, i - mp[xor_val]);
            else
                mp.insert({xor_val, i});
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
