class Solution {
public:
    vector<int> replaceNonCoprimes(vector<int>& nums) {
        stack<int> st;
        vector<int> ans;

        for(auto& num:nums){
            while(!st.empty()){
                int adj = st.top();
                int cur = num;

                int gcd = __gcd(num,adj);
                if(gcd == 1)
                    break;
                

                st.pop();
                num = lcm(num,adj);
            }
            st.push(num);
        }

        while(!st.empty()){
            ans.emplace_back(st.top());
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
static const auto kds = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();
