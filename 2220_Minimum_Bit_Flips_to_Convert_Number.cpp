class Solution {
public:
    string toBinary(int n) {
    string binary = "";
    while (n > 0) {
        binary = (n % 2 == 0 ? "0" : "1") + binary;
        n /= 2;
    }
    return binary;
}
    int minBitFlips(int start, int goal) {
        string s = toBinary(start);
        string g = toBinary(goal);
        int count=0;

        while (s.length() < g.length()) 
            s = "0" + s;
        while (g.length() < s.length())
            g = "0" + g;

        // cout<<s<<"  "<<g<<endl;
        for(int i=s.length()-1;i>=0;i--)
        {
            if(s == g)
                return count;
            else
            {
                if(s[i] == '0' && g[i] == '1')
                {
                    s[i] = '1';
                    count++;
                }
                else if(s[i] == '1' && g[i] == '0')
                {
                    s[i] = '0';
                    count++;
                }
                else
                    continue;
            }
        }
        return count;
    }
};
