class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        int n = nums.size();
        vector<int> arr;
        for(int i=0;i<n;i++)
            arr.emplace_back(nums[i]-i);

        unordered_map<int,int> freq;
        freq[arr[0]] = 1;
        long long bad_pairs= 0;

        for(int j = 1;j < n;j++){
            long long total_pairs = j;
            long long good_pairs = freq[arr[j]];

            bad_pairs += total_pairs - good_pairs;
            freq[arr[j]]++;
        }
        return bad_pairs;
    }
};
static const auto kds = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();
