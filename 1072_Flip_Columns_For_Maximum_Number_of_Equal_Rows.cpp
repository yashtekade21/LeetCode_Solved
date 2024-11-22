class Solution {
public:
    int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
        unordered_map<vector<int>, int,VectorHash> mp;

        for (auto row : matrix) {
            vector<int> id = row;
            if (row[0]) {
                id.clear();
                for (int i : row)
                    id.push_back(i ? 0 : 1);
            }
            mp[id]++;
        }
        int count = 0;
        for (auto x : mp)
            count = max(count, x.second);
        return count;
    }

private:
    // got to learn something new here
    struct VectorHash {
        size_t operator()(const vector<int>& v) const {
            size_t hash = 0;
            for (int i : v) 
                hash = hash * 31 + i;
            
            return hash;
        }
    };
};
static const auto kds = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();
