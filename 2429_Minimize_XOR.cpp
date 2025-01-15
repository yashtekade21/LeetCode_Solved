class Solution {
public:
    int minimizeXor(int num1, int num2) {
        int x = num1;
        int req_setbit_cnt = __builtin_popcount(num2);
        int cur_setbit_cnt = __builtin_popcount(x);
        int bit;
        if (cur_setbit_cnt == req_setbit_cnt) {
            return x;
        } else if (cur_setbit_cnt < req_setbit_cnt) {
            bit = 0;
            while (cur_setbit_cnt < req_setbit_cnt) {
                if (check_1_bit(x, bit) == false) {
                    update_1_bit(x, bit);
                    cur_setbit_cnt++;
                }
                bit++;
            }
        } else {
            bit = 0;
            if (cur_setbit_cnt > req_setbit_cnt) {
                while (cur_setbit_cnt > req_setbit_cnt) {
                    if (check_1_bit(x, bit) == true) {
                        update_0_bit(x, bit);
                        cur_setbit_cnt--;
                    }
                    bit++;
                }
            }
        }
        return x;
    }

private:
    bool check_1_bit(int& x, int& bit) { return x & (1 << bit); }

    void update_1_bit(int& x, int& bit) { x |= (1 << bit); }

    void update_0_bit(int& x, int& bit) { x &= ~(1 << bit); }
};
static const auto kds = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();
