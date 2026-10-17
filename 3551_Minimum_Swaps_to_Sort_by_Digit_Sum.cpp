class Solution {
public:
    int getDigitSum(int num) {
        int sum = 0;

        while (num > 0) {
            sum += num % 10;
            num /= 10;
        }
        return sum;
    }

    int minSwaps(vector<int>& nums) {
        int n = nums.size(), ans = 0;
        unordered_map<int, int> oldIdx;
        vector<int> numsSorted(nums);

        for (int i = 0; i < n; i++)
            oldIdx[nums[i]] = i;

        auto customSort = [this](int num1, int num2) {
            int n1Sum = getDigitSum(num1);
            int n2Sum = getDigitSum(num2);

            if (n1Sum == n2Sum)
                return num1 < num2;

            return n1Sum < n2Sum;
        };

        sort(numsSorted.begin(), numsSorted.end(), customSort);

        for (int i = 0; i < n; i++) {
            int reqVal = numsSorted[i];
            int currVal = nums[i];

            if (reqVal == currVal)
                continue;

            int idx = oldIdx[reqVal];

            nums[i] = reqVal;
            nums[idx] = currVal;

            oldIdx[reqVal] = i;
            oldIdx[currVal] = idx;

            ans++;
        }

        return ans;
    }
};
