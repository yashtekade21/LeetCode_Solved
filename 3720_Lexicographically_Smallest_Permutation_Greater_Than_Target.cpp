class Solution {
public:
    string lexGreaterPermutation(string s, string target) {
        vector<int> count(26, 0);
        string ans = "";

        for (char& ch : s)
            count[ch - 'a']++;

        string curr;

        solve(curr, count, target, ans, 0, false);

        return ans;
    }

private:
    bool solve(string& curr, vector<int>& count, string& target, string& ans,
               int i, bool greater) {
        if (i == target.length()) {
            if (greater) {
                ans = curr;
                return true;
            }
            return false;
        }

        for (char ch = 'a'; ch <= 'z'; ch++) {
            if (count[ch - 'a'] == 0)
                continue;

            if (greater == false && ch < target[i])
                continue;

            curr.push_back(ch);
            count[ch - 'a']--;

            bool isGreater = greater || ch > target[i];

            if (solve(curr, count, target, ans, i + 1, isGreater))
                return true;

            curr.pop_back();
            count[ch - 'a']++;
        }

        return false;
    }
};
static const auto kds = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();
