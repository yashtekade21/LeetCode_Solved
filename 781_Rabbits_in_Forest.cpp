class Solution {
public:
    int numRabbits(vector<int>& answers) {
        int n = answers.size();
        unordered_map<int, int> mp;

        for (auto& num:answers)
            mp[num]++;
        

        int ans = 0;
        for (auto& [x, count] : mp)
            ans += ceil((double)count / (x + 1)) * (x + 1);
        
        return ans;
    }
};
static const auto kds = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();
