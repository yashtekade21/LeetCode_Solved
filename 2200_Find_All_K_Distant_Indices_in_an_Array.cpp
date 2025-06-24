class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        int n = nums.size();
        vector<bool> kDistantIdx(1001, false);
        vector<int> keyIdx;

        for (int i = 0; i < n; i++) {
            if (nums[i] == key){
                keyIdx.emplace_back(i);
                kDistantIdx[i] = true;
            }
        }

        for (int& idx : keyIdx) {
            int minIdx = max(0, idx - k);
            int maxIdx = min(n - 1, idx + k);

            for (int i = minIdx; i <= maxIdx; i++) {
                if (kDistantIdx[i] == false)
                    kDistantIdx[i] = true;
            }
        }

        vector<int> ans;
        for (int i = 0; i <= 1000; i++) {
            if (kDistantIdx[i])
                ans.emplace_back(i);
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
