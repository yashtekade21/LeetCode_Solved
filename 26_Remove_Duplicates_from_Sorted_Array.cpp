class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        set<int> st;
        for(auto i:nums)
            st.insert(i);

        int index=0;
        for(auto i:st){
            nums[index] = i;
            index++;
        }
        return index;
    }
};
static const auto kds = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return 0;
}();
