class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        int i = 0;
        long long total=0;
        for (int e : chalk) {
            total += e;
        }
        cout<<total;
        int remChalk = k % total;

        while (remChalk >= 0) {
            if (remChalk >= chalk[i])
                remChalk -= chalk[i];
            else {
                break;
            }
            i++;
        }
        return i;
    }
};
