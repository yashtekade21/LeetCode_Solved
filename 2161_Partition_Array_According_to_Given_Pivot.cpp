class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int n = nums.size();
        vector<int> result(n);

        int lessThan = 0, equalTo = 0, moreThan = 0;

        for (int& num : nums) {
            if (num > pivot) {
                moreThan++;
            } else if (num < pivot) {
                lessThan++;
            } else {
                equalTo++;
            }
        }

        int i = 0, j = lessThan, k = lessThan + equalTo;

        for (auto& num : nums) {
            if (num > pivot) {
                result[k] = num;
                k++;
            } else if (num < pivot) {
                result[i] = num;
                i++;
            }
        }

        while (equalTo > 0) {
            result[j] = pivot;
            j++;
            equalTo--;
        }
        return result;
    }
};
static const auto kds = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();
