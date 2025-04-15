class Solution {
public:
    long long goodTriplets(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();

        vector<int> mp(n, 0);
        for (int i = 0; i < n; i++)
            mp[nums2[i]] = i;

        vector<int> segmentTree(n * 4, 0);
        long long ans = 0;

        updateST(0, n - 1, 0, mp[nums1[0]], segmentTree);

        for (int i = 1; i < n; i++) {
            int idx = mp[nums1[i]];
            long long leftCommonCount = queryST(0, idx, 0, n - 1, 0, segmentTree);
            long long leftNotCommonCount = i - leftCommonCount;
            long long elementsAfterIdxNums2 = (n - 1) - idx;
            long long rightCommonCount = elementsAfterIdxNums2 - leftNotCommonCount;
            ans += leftCommonCount * rightCommonCount;

            updateST(0, n - 1, 0, idx, segmentTree);
        }

        return ans;
    }

private:
    void updateST(int l, int r, int i, int updateIndex,
                  vector<int>& segmentTree) {
        if (l == r) {
            segmentTree[i] = 1;
            return;
        }

        int mid = (l + r) / 2;
        if (updateIndex <= mid) {
            updateST(l, mid, 2 * i + 1, updateIndex, segmentTree);
        } else {
            updateST(mid + 1, r, 2 * i + 2, updateIndex, segmentTree);
        }

        segmentTree[i] = segmentTree[2 * i + 1] + segmentTree[2 * i + 2];
    }

    int queryST(int queryStart, int queryEnd, int l, int r, int i,
                vector<int>& segmentTree) {
        if (r < queryStart || l > queryEnd)
            return 0;

        if (l >= queryStart && r <= queryEnd)
            return segmentTree[i];

        int mid = (l + r) / 2;
        int left =
            queryST(queryStart, queryEnd, l, mid, 2 * i + 1, segmentTree);
        int right =
            queryST(queryStart, queryEnd, mid + 1, r, 2 * i + 2, segmentTree);

        return left + right;
    }
};
static const auto kds = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();
