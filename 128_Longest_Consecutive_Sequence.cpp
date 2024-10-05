class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        if(n==0)
            return 0;
        
        int longest = 1;
        unordered_set<int> st;

        for(auto i:nums)
            st.insert(i);

        for(auto i:st){
            if(st.find(i-1) == st.end()){
                int curcnt = 1,x=i;
                while(st.find(x+1) != st.end()){
                    curcnt++;
                    x++;
                }
                longest = max(longest,curcnt);
            }
        }
        return longest;
    }
};
static const auto kds = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return 0;
}();
