class Solution {
public:
    long long kthSmallestProduct(vector<int>& nums1, vector<int>& nums2,
                                 long long k) {
        int n = nums1.size();
        int m = nums2.size();

        // long long l = 1LL * nums1[0] * nums2[0];         // minProduct
        // long long r = 1LL * nums1[n - 1] * nums2[m - 1]; // maxProduct

        long long l = -1e10, r = 1e10; 
        long long ans = 0;

        while (l <= r) {
            long long mid = (l + r) / 2; // midProduct

            long long cntSmallestProd =
                findcntOfSmallestProduct(nums1, nums2, mid);

            if (cntSmallestProd >= k) {
                ans = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return ans;
    }

private:
    long long findcntOfSmallestProduct(vector<int>& nums1, vector<int>& nums2,
                                       long long midProduct) {
        long long prodCnt = 0;
        int n = nums1.size();
        int m = nums2.size();

        for (int i = 0; i < n; i++) {

            if (nums1[i] >= 0) {
                int l = 0;
                int r = m - 1;
                int M = -1;

                while (l <= r) {
                    int mid = (l + r) / 2;
                    long long product = 1LL * nums1[i] * nums2[mid];

                    if (product <= midProduct) {
                        M = mid;
                        l = mid + 1;
                    } else {
                        r = mid - 1;
                    }
                }
                prodCnt += (M + 1);
            } else {
                int l = 0;
                int r = m - 1;
                int M = m;

                while (l <= r) {
                    int mid = (l + r) / 2;
                    long long product = 1LL * nums1[i] * nums2[mid];

                    if (product <= midProduct) {
                        M = mid;
                        r = mid - 1;
                    } else {
                        l = mid + 1;
                    }
                }
                prodCnt += (m - M);
            }
        }
        return prodCnt;
    }
};
static const auto kds = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();
