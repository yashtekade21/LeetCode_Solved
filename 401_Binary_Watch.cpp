class Solution {
public:
    vector<string> readBinaryWatch(int turnedOn) {
        vector<string> ans;
        for (int h = 0; h <= 11; h++) {
            for (int m = 0; m <= 59; m++) {
                int h_bits = __builtin_popcount(h);
                int m_bits = __builtin_popcount(m);

                if (h_bits + m_bits == turnedOn) {
                    string time = to_string(h) + ":";
                    if (m < 10)
                        time = time + "0" + to_string(m);
                    else
                        time += to_string(m);
                    ans.push_back(time);
                }
            }
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
