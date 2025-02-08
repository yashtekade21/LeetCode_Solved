class NumberContainers {
public:
    unordered_map<int, set<int>> number_to_index;
    unordered_map<int, int> index_to_number;
    NumberContainers() {}

    void change(int index, int number) {
        if (index_to_number.find(index) != index_to_number.end()) {
            int old_number = index_to_number[index];
            number_to_index[old_number].erase(index);

            if (number_to_index[old_number].empty())
                number_to_index.erase(old_number);
        }

        index_to_number[index] = number;
        number_to_index[number].insert(index);
    }

    int find(int number) {
        if(number_to_index.find(number) != number_to_index.end() && !number_to_index[number].empty())
            return *number_to_index[number].begin();

        return -1;
    }
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */
 static const auto kds = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();
