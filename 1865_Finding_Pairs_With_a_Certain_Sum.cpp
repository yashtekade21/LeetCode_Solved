class FindSumPairs {
public:
    unordered_map<int, int> mp1, mp2;
    vector<int> vec2;
    FindSumPairs(vector<int>& nums1, vector<int>& nums2) {
        vec2 = nums2;

        for (auto& num : nums1)
            mp1[num]++;

        for (auto& num : nums2)
            mp2[num]++;
    }

    void add(int index, int val) {
        mp2[vec2[index]]--;
        vec2[index] += val;
        mp2[vec2[index]]++;
    }

    int count(int tot) {
        int cnt = 0;
        for (auto& item : mp1) {
            int num1 = item.first;
            int freq1 = item.second;

            int num2 = tot - num1;
            int freq2 = mp2[tot - num1];

            cnt += (freq1 * freq2);
        }
        return cnt;
    }
};
static const auto kds = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

/**
 * Your FindSumPairs object will be instantiated and called as such:
 * FindSumPairs* obj = new FindSumPairs(nums1, nums2);
 * obj->add(index,val);
 * int param_2 = obj->count(tot);
 */
