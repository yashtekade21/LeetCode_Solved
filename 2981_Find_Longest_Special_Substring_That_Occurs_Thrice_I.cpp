template <typename T1, typename T2> struct pair_hash {
    std::size_t operator()(const std::pair<T1, T2>& p) const {
        auto h1 = std::hash<T1>{}(p.first);
        auto h2 = std::hash<T2>{}(p.second);
        return h1 ^ h2;
    }
};

class Solution {
public:
    int maximumLength(std::string s) {
        int n = s.length();
        unordered_map<std::pair<char, int>, int, pair_hash<char, int>> mp;

        for (int i = 0; i < n; i++) {
            char ch = s[i];
            int l = 0;
            for (int j = i; j < n; j++) {
                if (s[j] == ch) {
                    l++;
                    mp[{ch, l}]++;
                } else
                    break;
            }
        }

        int ans = 0;
        for (auto it : mp) {
            int len = it.first.second;
            int freq = it.second;

            if (freq >= 3 && len > ans)
                ans = len;
        }

        if (ans == 0)
            return -1;
        return ans;
    }
};
static const auto kds = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();
