class ProductOfNumbers {
public:
    vector<int> pre_sum{1};
    ProductOfNumbers() {}

    void add(int num) {
        if (num > 0)
            pre_sum.emplace_back(num * pre_sum.back());
        else {
            pre_sum.clear();
            pre_sum.emplace_back(1);
        }
    }

    int getProduct(int k) {
        if (k < pre_sum.size())
            return pre_sum.back() / pre_sum[pre_sum.size() - k - 1];

        return 0;
    }
};
static const auto kds = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();
/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */
