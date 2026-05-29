class Solution {
public:
    int minElement(vector<int>& nums) {
        int ans = INT_MAX;
        for (auto& num : nums)
            ans = min(ans, digSum(num));

        return ans;
    }

private:
    int digSum(int num) {
        int sum = 0;
        while (num > 0) {
            sum += (num % 10);
            num /= 10;
        }
        return sum;
    }
};
