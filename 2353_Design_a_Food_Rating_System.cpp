class FoodRatings {
public:
    unordered_map<string, int> foodRateMp;
    unordered_map<string, string> foodCuisineMp;
    unordered_map<string, set<pair<int, string>>> cuisineRateFoodMp;

    FoodRatings(vector<string>& foods, vector<string>& cuisines,
                vector<int>& ratings) {
        int n = foods.size();
        for (int i = 0; i < n; i++) {
            foodRateMp[foods[i]] = ratings[i];
            foodCuisineMp[foods[i]] = cuisines[i];
            cuisineRateFoodMp[cuisines[i]].insert({-ratings[i], foods[i]});
        }
    }

    void changeRating(string food, int newRating) {
        int oldRate = foodRateMp[food];
        string cuisine = foodCuisineMp[food];
        foodRateMp[food] = newRating;
        cuisineRateFoodMp[cuisine].erase({-oldRate, food});
        cuisineRateFoodMp[cuisine].insert({-newRating, food});
    }

    string highestRated(string cuisine) {
        return cuisineRateFoodMp[cuisine].begin()->second;
    }
};

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */
static const auto kds = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();
