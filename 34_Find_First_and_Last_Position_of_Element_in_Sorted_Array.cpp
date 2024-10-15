class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        int first = firstOcc(nums, n, target);
        if (first == -1)
            return {-1, -1};
        int last = lastOcc(nums, n, target);

        return {first, last};
    }

private:
    int firstOcc(vector<int>& arr, int n, int target) {
        int low = 0, high = n - 1;
        int first = -1;

        while (low <= high) {
            int mid = (low + high) / 2;
            if (arr[mid] == target) {
                first = mid;
                high = mid - 1;
            } else if (arr[mid] < target)
                low = mid + 1;
            else
                high = mid - 1;
        }
        return first;
    }

    int lastOcc(vector<int>& arr, int n, int target) {
        int low = 0, high = n - 1;
        int last = -1;
        while (low <= high) {
            int mid = (low + high) / 2;
            if (arr[mid] == target) {
                last = mid;
                low = mid + 1;
            } else if (arr[mid] < target)
                low = mid + 1;
            else
                high = mid - 1;
        }
        return last;
    }
};
static const auto kds = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();
