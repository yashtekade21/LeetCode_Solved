class Solution {
public:
    string triangleType(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        if(nums[0] + nums[1] <= nums[2])
            return "none";
        
        unordered_set<int> sides;
        for (auto& side : nums)
            sides.insert(side);

        int setSize = sides.size();
        if (setSize == 1)
            return "equilateral";
        else if (setSize == 2)
            return "isosceles";

        return "scalene";
    }
};
static const auto kds = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();
