class Solution {
public:
    string digitSum(string s, int k) {
        while (s.length() > k) {
            int n = s.length();

            string new_s;
            int i = 0;
            while (i < n) {
                new_s += digitSum(s.substr(i, k));
                i += k;
            }
            s = new_s;
        }
        return s;
    }

private:
    string digitSum(string num) {
        int sum = 0;
        for (char& c : num)
            sum += c - '0';

        return to_string(sum);
    }
};
static const auto kds = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();
