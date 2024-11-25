class Solution {
public:
    int slidingPuzzle(vector<vector<int>>& board) {
        vector<vector<int>> nb;
        string s = "";
        set<string> visited;
        deque<Item> q;

        nb = {{1, 3}, {0, 2, 4}, {1, 5}, {0, 4}, {1, 3, 5}, {2, 4}};
        //       0         1        2       3        4         5
        for (auto r : board)
            for (auto i : r)
                s += to_string(i);

        q.push_back({(int)s.find('0'), s,
                     0}); // index of 0, str of matrix, no. of moves
        visited.insert(s);

        while (!q.empty()) {
            Item pos = q.front();
            q.pop_front();

            if (pos.s == "123450")
                return pos.moves;

            for (auto j : nb[pos.idx]) {
                string cpy = pos.s; 
                swap(cpy[pos.idx], cpy[j]);

                if (visited.find(cpy) == visited.end()) {
                    q.push_back({j, cpy, pos.moves + 1});
                    visited.insert(cpy);
                }
            }
        }
        return -1;
    }

private:
    struct Item {
        int idx;
        string s;
        int moves;
    };
};
static const auto kds = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();
