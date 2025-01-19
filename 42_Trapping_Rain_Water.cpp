class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int total_water = 0;
        vector<int> left_max = LeftMaxArr(height, n),
                    right_max = RightMaxArr(height, n);

        for(int i=0;i<n;i++){
            total_water += min(left_max[i],right_max[i]) - height[i];
        }
        return total_water;
    }

private:
    vector<int> LeftMaxArr(vector<int>& height, int n) {
        vector<int> left_arr(n);
        left_arr[0] = height[0];
        for (int i = 1; i < n; i++) {
            left_arr[i] = max(left_arr[i-1], height[i]);
        }

        return left_arr;
    }
    vector<int> RightMaxArr(vector<int>& height, int n) {
        vector<int> right_arr(n);
        right_arr[n - 1] = height[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            right_arr[i] = max(height[i], right_arr[i + 1]);
        }
        return right_arr;
    }
};
static const auto kds = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();
