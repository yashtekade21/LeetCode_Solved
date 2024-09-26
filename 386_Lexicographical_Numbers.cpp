class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<string> vec;
        vector<int> ans;
        for (int i = 0; i < n; i++)
            vec.emplace_back(to_string(i + 1));

        sort(vec.begin(),vec.end());

        // for(auto i:vec)
        //     cout<<i<<" ";
        for(auto x : vec)
            ans.emplace_back(stoi(x));

        vec.clear();

        return ans;
    }
};

static const auto kds = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return 0;
}();
