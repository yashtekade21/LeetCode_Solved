class Solution {
public:
    long long gridGame(vector<vector<int>>& grid) {
        long long first_row_rem = accumulate(grid[0].begin(),grid[0].end(),0LL);
        int n = grid[0].size();

        long long second_row_rem = 0;
        long long min_rob2_sum = LONG_LONG_MAX;

        for(int rob1_col=0;rob1_col<n;rob1_col++){
            first_row_rem -= grid[0][rob1_col];

            long long max_rob2_sum = max(first_row_rem,second_row_rem);

            min_rob2_sum = min(min_rob2_sum,max_rob2_sum);

            second_row_rem += grid[1][rob1_col];
        }
        return min_rob2_sum;
    }
};
static const auto kds = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();
