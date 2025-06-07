class Solution {
public:
    string clearStars(string s) {
        int n = s.length();

        string ans = "";
        priority_queue<pair<char, int>, vector<pair<char, int>>,
                       greater<pair<char, int>>>
            pq;
        unordered_map<int, bool> mp;

        for (int i = 0; i < n; i++) {
            if (!pq.empty() && s[i] == '*') {
                int idx = pq.top().second; // will be -ve
                mp[-1 * idx] = true;
                pq.pop();
            } else
                pq.push({s[i], -1 * i});
        }
        
        for (int i = 0; i < n; i++) {
            if (mp[i] || s[i] == '*')
                continue;
            ans += s[i];
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
