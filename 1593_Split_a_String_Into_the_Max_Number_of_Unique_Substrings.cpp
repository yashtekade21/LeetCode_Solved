class Solution {
public:
    int maxi;
    int maxUniqueSplit(string s) {
        maxi = 0;
        unordered_set<string> us;
        check(s, us, 0);
        return maxi;
    }

private:
    void check(string s, unordered_set<string> us, int index) {
        int n = s.length();
        if (index == n) {
            maxi = max(maxi, (int)us.size());
            return;
        }
        string subs = "";
        for (int i = index; i < n; i++) {
            subs += s[i];
            if (!us.contains(subs)) {
                us.insert(subs);
                check(s, us, i + 1);
                us.erase(subs);
            }
        }
        return;
    }
};
static const auto kds = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();
