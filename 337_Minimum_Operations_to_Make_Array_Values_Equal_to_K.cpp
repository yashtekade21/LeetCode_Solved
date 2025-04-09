class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int n = nums.size();

        unordered_set<int> st;
        for(auto& num:nums){
            if(num < k)
                return -1;
            
            st.insert(num);
        }
        int ans = 0;
        for(auto& num:st){
            if(num > k)
                ans++;
        }

        return ans;
    }
};
static const auto kds = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();
