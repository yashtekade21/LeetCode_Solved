class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int> temp = arr;
        unordered_map<int, int> mp;
        int rank = 1;

        sort(temp.begin(), temp.end());

        for (int i = 0; i < temp.size(); i++) {
            if (mp.find(temp[i]) == mp.end())
                mp[temp[i]] = rank++;
        }

        for(int i=0;i<arr.size();i++)
            arr[i] = mp[arr[i]];

        return arr;
    }
};
static const auto kds = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return 0;
}();
