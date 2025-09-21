class MovieRentingSystem {
public:
    unordered_map<int, set<pair<int, int>>> unrentedMp;
    unordered_map<int, set<pair<int, int>>> moviePriceMp;
    set<tuple<int, int, int>> rentedSt;
    MovieRentingSystem(int n, vector<vector<int>>& entries) {
        for (auto& entry : entries) {
            int shop = entry[0];
            int movie = entry[1];
            int price = entry[2];

            unrentedMp[movie].insert({price, shop});
            moviePriceMp[movie].insert({shop,price});
        }
    }

    vector<int> search(int movie) {
        vector<int> top5;
        int cnt = 0;
        if (unrentedMp.find(movie) == unrentedMp.end())
            return top5;

        for (auto& [_, shop] : unrentedMp[movie]) {
            top5.push_back(shop);
            if (++cnt == 5)
                break;
        }
        return top5;
    }

    void rent(int shop, int movie) {
        auto it = moviePriceMp[movie].lower_bound({shop, INT_MIN});
        int price = it->second;

        unrentedMp[movie].erase({price, shop});
        rentedSt.insert({price, shop, movie});
        return;
    }

    void drop(int shop, int movie) {
        auto it = moviePriceMp[movie].lower_bound({shop, INT_MIN});
        int price = it->second;

        unrentedMp[movie].insert({price, shop});
        rentedSt.erase({price, shop, movie});
        return;
    }

    vector<vector<int>> report() {
        vector<vector<int>> rented;
        int cnt = 0;

        for (auto& [price, shop, movie] : rentedSt) {
            rented.push_back({shop, movie});
            if (++cnt == 5)
                break;
        }
        return rented;
    }
};

/**
 * Your MovieRentingSystem object will be instantiated and called as such:
 * MovieRentingSystem* obj = new MovieRentingSystem(n, entries);
 * vector<int> param_1 = obj->search(movie);
 * obj->rent(shop,movie);
 * obj->drop(shop,movie);
 * vector<vector<int>> param_4 = obj->report();
 */
static const auto kds = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();
