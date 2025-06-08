class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<int> ans;

        for (int i = 1; i <= 9; i++)
            dfs(i, n, ans);

        return ans;
    }

private:
    void dfs(int num, int n, vector<int>& ans) {
        if (num > n)
            return;

        ans.emplace_back(num);

        for (int i = 0; i <= 9; i++) {
            int newNum = num * 10 + i;
            if (newNum > n)
                return;
                
            dfs(newNum, n, ans);
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
