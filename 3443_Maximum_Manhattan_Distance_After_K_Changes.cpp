class Solution {
public:
    int maxDistance(string s, int k) {
        int n = s.length();
        int ans = 0;

        int north = 0, south = 0, east = 0, west = 0;

        for (int i = 0; i < n; i++) {
            if (s[i] == 'N')
                north++;
            else if (s[i] == 'S')
                south++;
            else if (s[i] == 'E')
                east++;
            else
                west++;

            int curDist = calManhattenDist(west - east, south - north);

            int unitsDone = i + 1;
            int requiredUnits = unitsDone - curDist;

            int improvedUnits = 0;
            if (unitsDone != curDist) {
                improvedUnits = min(2 * k, requiredUnits);
                // k--;
            }

            ans = max(ans, curDist + improvedUnits);
        }
        return ans;
    }

private:
    int calManhattenDist(int x, int y) {
        // x2 = 0 and y2 = 0  finding dist from origin (0,0)

        return abs(x) + abs(y);
    }
};
