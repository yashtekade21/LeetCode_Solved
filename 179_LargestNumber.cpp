class Solution {
public:
    static int compare_str(string s1, string s2) {
        // int i = 0, j = 0;

        // while (i < s1.length() || j < s2.length()) {
        //     if (i == s1.length())
        //         i = 0;
        //     if (j == s2.length())
        //         j = 0;
        //     // if(i == s1.length() && j == s2.length())
        //     //     break;
        //     if (s1[i] > s2[j])
        //         return -1;
        //     if (s1[i] < s2[j])
        //         return 1;

        //     i++;
        //     j++;
        // }
        // return 0;
        return s1 + s2 > s2 + s1;
    }
    string largestNumber(vector<int>& nums) {

        vector<string> v;
        for (auto i : nums)
            v.emplace_back(to_string(i));

        sort(v.begin(), v.end(), compare_str);
        if (v[0] == "0")
            return "0";

        string ans = accumulate(v.begin(), v.end(), string());
        return ans;
    }
};
static const auto kds = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return 0;
}();
