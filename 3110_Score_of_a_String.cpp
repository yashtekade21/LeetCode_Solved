class Solution {
public:
    int scoreOfString(string s) {
        int sum=0;
        for(int i=0;i<s.length()-1;i++)
        {
            char c1 = s[i],c2 = s[i+1];
            sum += abs(c1-c2);
        }
        return sum;
    }
};
