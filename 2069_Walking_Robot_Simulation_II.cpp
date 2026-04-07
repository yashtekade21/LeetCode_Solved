class Robot {
public:
    vector<vector<int>> linGrid;
    bool moved = false;
    int idx = 0;
    Robot(int width, int height) {
        // Left->Right
        for (int i = 0; i < width; i++)
            linGrid.push_back({i, 0, 0}); // {i->x,0->y,0->dir}

        // Bottom->Up
        for (int j = 1; j < height; j++)
            linGrid.push_back({width - 1, j, 1});

        // Right->Left
        for (int i = width - 2; i >= 0; i--)
            linGrid.push_back({i, height - 1, 2});

        // Top->Bottom
        for (int j = height - 2; j > 0; j--)
            linGrid.push_back({0, j, 3});

        linGrid[0][2] = 3; // After round completion robot will face south
    }

    void step(int num) {
        moved = true;
        idx = (idx + num) % linGrid.size();
    }

    vector<int> getPos() { return {linGrid[idx][0], linGrid[idx][1]}; }

    string getDir() {
        int dir = linGrid[idx][2];
        if (dir == 0 || !moved)
            return "East";
        else if (dir == 1)
            return "North";
        else if (dir == 2)
            return "West";

        return "South";
    }
};
static const auto kds = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

/**
 * Your Robot object will be instantiated and called as such:
 * Robot* obj = new Robot(width, height);
 * obj->step(num);
 * vector<int> param_2 = obj->getPos();
 * string param_3 = obj->getDir();
 */
