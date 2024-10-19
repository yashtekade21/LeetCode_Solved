class Solution {
public:
    char findKthBit(int n, int k) {
        int size = pow(2, n) - 1;
        return find(size, k - 1);
    }

private:
    char find(int size, int k) {
        if (size == 1)
            return '0';

        int mid = (size / 2);

        if (k == mid)
            return '1';
        else if (k < mid)
            return find(mid, k);
        else {
            if (find(mid, size - k - 1) == '0')
                return '1';
            else
                return '0';
        }
        return '0';
    }
};
static const auto kds = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();
