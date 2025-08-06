class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int n = fruits.size();

        vector<int> segmentTree(4 * n, -1);

        buildSegTree(0, 0, n - 1, baskets, segmentTree); // i=0, l=0, r=n-1

        int ans = 0;
        for (auto& fruit : fruits) {
            if (canPlace(0, 0, n - 1, segmentTree, fruit) != true) {
                ans++;
            }
        }
        return ans;
    }

private:
    void buildSegTree(int i, int l, int r, vector<int>& baskets,
                      vector<int>& segmentTree) {
        if (l == r) {
            segmentTree[i] = baskets[l];
            return;
        }

        int mid = (l + r) / 2;
        buildSegTree(2 * i + 1, l, mid, baskets, segmentTree);
        buildSegTree(2 * i + 2, mid + 1, r, baskets, segmentTree);

        segmentTree[i] = max(segmentTree[2 * i + 1], segmentTree[2 * i + 2]);

        return;
    }

    bool canPlace(int i, int l, int r, vector<int>& segmentTree, int fruit) {
        if (segmentTree[i] < fruit)
            return false;

        if (l == r) {
            segmentTree[i] = -1;
            return true;
        }

        int mid = (l + r) / 2;
        bool placed = true;

        if (segmentTree[2 * i + 1] >= fruit) {
            placed = canPlace(2 * i + 1, l, mid, segmentTree, fruit);
        } else {
            placed = canPlace(2 * i + 2, mid + 1, r, segmentTree, fruit);
        }

        segmentTree[i] = max(segmentTree[2 * i + 1], segmentTree[2 * i + 2]);

        return placed;
    }
};
static const auto kds = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();
