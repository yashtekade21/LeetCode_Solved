class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        int n = queries.size();
        vector<int> result;

        unordered_map<int, int> color_mp;    // ith color count
        unordered_map<int,int> ball_mp; // ith ball changed to new color

        for (auto& query : queries) {
            int ball = query[0];
            int color = query[1];

            if (ball_mp.find(ball) != ball_mp.end()) {
                int last_color = ball_mp[ball];
                color_mp[last_color]--;

                if (color_mp[last_color] == 0)
                    color_mp.erase(last_color);
            }

            ball_mp[ball] = color;
            color_mp[color]++;

            result.emplace_back(color_mp.size());
        }
        return result;
    }
};
static const auto kds = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();
