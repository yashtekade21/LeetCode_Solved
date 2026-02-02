class Solution {
public:
    typedef pair<long long, long long> P;
    long long minimumCost(vector<int>& nums, int k, int dist) {
        int n = nums.size();
        set<P> kMinCost, remMinCost;

        long long sum = 0;

        int i = 1;
        while (i <= dist) {
            kMinCost.insert({nums[i], i});
            sum += nums[i];
            if (kMinCost.size() > k - 1) {
                P temp = *kMinCost.rbegin();
                kMinCost.erase(temp);
                remMinCost.insert(temp);

                sum -= temp.first;
            }
            i++;
        }

        long long ans = LLONG_MAX;
        while (i < n) {
            kMinCost.insert({nums[i], i});
            sum += nums[i];
            if (kMinCost.size() > k - 1) {
                P temp = *kMinCost.rbegin();
                kMinCost.erase(temp);
                remMinCost.insert(temp);

                sum -= temp.first;
            }
            ans = min(ans, sum);
            P slided = {nums[i - dist], i - dist};
            if (kMinCost.find(slided) != kMinCost.end()) {
                kMinCost.erase(slided);
                sum -= slided.first;
                if (!remMinCost.empty()) {
                    P shifted = *remMinCost.begin();
                    kMinCost.insert(shifted);
                    remMinCost.erase(shifted);
                    sum += shifted.first;
                }
            } else {
                remMinCost.erase(slided);
            }
            i++;
        }
        return ans + nums[0];
    }
};
static const auto kds = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();
