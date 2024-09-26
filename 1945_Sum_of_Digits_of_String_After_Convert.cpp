class Solution {
public:
    int getLucky(string s, int k) {
        string res = "";

        for (int i = 0; i < s.length(); i++) {
            int x = (s[i] - 'a');
            string str = to_string(x + 1);
            res += str;
        }

        int sum = 0;
        for (int i = 0; i < res.size(); i++) {
            sum += (res[i] - '0');
        }

        int num = sum;
        while (--k) {
            sum = 0;
            while (num > 0) {
                int rem = num % 10;
                sum += rem;
                num /= 10;
            }
            num = sum;
        }
        return sum;
    }
};
