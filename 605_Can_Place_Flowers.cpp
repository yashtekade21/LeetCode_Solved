class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int size = flowerbed.size();
        int count = 0;
        for (int i = 0; i < size; i++) {
            if (flowerbed[i] == 1) {
                i++;
                continue;
            }

            if ((i == 0 || flowerbed[i - 1] == 0) &&
                (i == size - 1 || flowerbed[i + 1] == 0)) {
                count++;
                flowerbed[i] = 1;

                if(count >= n)
                    break;
                i++;
            }
        }
        cout<<count<<endl;
        return count >= n;
    }
};
static const auto kds = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();
