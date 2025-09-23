class Solution {
public:
    int compareVersion(string version1, string version2) {
        vector<string> vec1, vec2;

        vec1 = getSplittedString(version1);
        vec2 = getSplittedString(version2);
        int v1 = vec1.size(), v2 = vec2.size();

        int i = 0;
        while (i < v1 || i < v2) {
            int num1 = i < v1 ? stoi(vec1[i]) : 0;
            int num2 = i < v2 ? stoi(vec2[i]) : 0;

            if (num1 == num2)
                i++;
            else if (num1 > num2)
                return 1;
            else
                return -1;
        }
        return 0;
    }

private:
    vector<string> getSplittedString(string& version) {
        vector<string> vec;

        stringstream ss(version);
        string part;
        while (getline(ss, part, '.')) {
            vec.push_back(part);
        }
        return vec;
    }
};
static const auto kds = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();
