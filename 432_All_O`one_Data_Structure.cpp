class AllOne {
protected:
    unordered_map<string,int> freq;
    unordered_map<int,unordered_set<string>> map;
    int min,max;

public:
    AllOne() {
        min = 0;
        max = 0;
    }
    
    void inc(string key) {
        if(freq.find(key) == freq.end()){
            freq[key]++;
            map[freq[key]].insert(key);
            min = 1;
            if(max<1)
                max++;
        }
        else{
            map[freq[key]].erase(key);

            if(min == freq[key] && map[freq[key]].empty())
                min++;

            freq[key]++;
            map[freq[key]].insert(key);

            if(freq[key] > max)
                max = freq[key];
        }
    }
    
    void dec(string key) {
        map[freq[key]].erase(key);

        if(min == freq[key] && map[freq[key]].empty())
            min--;

        if(freq[key] == max && map[freq[key]].empty())
            max--;

        freq[key]--;

        if(freq[key] > 0)
            map[freq[key]].insert(key);
        else
            freq.erase(key);
    }
    
    string getMaxKey() {
        if(map[max].empty() == false)
            return *map[max].begin();

        return "";
    }
    
    string getMinKey() {
        if(map[min].empty() == false)
            return *map[min].begin();

        if(min == 0 && freq.empty() == false)
        {
            while(map[min].empty())
                min++;

            return *map[min].begin();
        }
        return "";
    }
};

/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne* obj = new AllOne();
 * obj->inc(key);
 * obj->dec(key);
 * string param_3 = obj->getMaxKey();
 * string param_4 = obj->getMinKey();
 */

 static const auto kds = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return 0;
}();
