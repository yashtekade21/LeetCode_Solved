class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();

        set<int> st;

        for(int& num:nums){
            st.insert(num);
        }

        int misNum = 1;

        for(auto& num:st){
            if(num <= 0)
                continue;
            
            if(num != misNum)
                break;
            
            misNum++;  
        }
        return misNum;
    }
};
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();

        int i = 0, j = 0;
        int maxNum = INT_MIN;
        vector<int> ans;
        while (j < n) {
            maxNum = max(maxNum, nums[j]);

            if (j - i + 1 == k) {
                ans.emplace_back(maxNum);
                if (nums[i] == maxNum) {
                    maxNum = INT_MIN;
                    for (int z = i + 1; z < i + k; z++) {
                        maxNum = max(maxNum, nums[z]);
                    }
                }
                i++;
            }
            j++;
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
