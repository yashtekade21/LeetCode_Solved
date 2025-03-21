class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes,
                                  vector<vector<string>>& ingredients,
                                  vector<string>& supplies) {
        int r = recipes.size(), n = ingredients.size();

        unordered_set<string> supplySet;

        for (auto& supply : supplies) {
            supplySet.insert(supply);
        }

        bool allCooked = false;
        vector<string> ans;
        vector<bool> recipeCooked(r, false);

        while (!allCooked) {
            allCooked = true;

            for (int i = 0; i < n; i++) {
                if (!recipeCooked[i]) {
                    bool missing = false;
                    for (auto& need : ingredients[i]) {
                        if (supplySet.find(need) == supplySet.end()) {
                            missing = true;
                            break;
                        }
                    }
                    if (!missing) {
                        string recipe = recipes[i];
                        ans.push_back(recipe);
                        supplySet.insert(recipe);
                        recipeCooked[i] = true;
                        allCooked = false;
                    }
                }
            }
        }
        return ans;
    }
};
static const auto kds = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();
