class CustomStack {
public:
    stack<int> s;
    int capacity;
    vector<int> values;
    CustomStack(int maxSize) {
        capacity = maxSize;
        values.resize(maxSize,0);
    }
    
    void push(int x) {
        if(s.size()<capacity)
            s.push(x);
    }
    
    int pop() {
        if(s.empty())
            return -1;
        int top = s.top();
        s.pop();
        top+=values[s.size()];
        if(s.size() > 0)
            values[s.size()-1] += values[s.size()];
        values[s.size()] = 0;
        return top;
        
    }
    
    void increment(int k, int val) {
        int temp = min(k-1,static_cast<int>(s.size()-1));
        if(temp >= 0)
            values[temp] += val;
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */
static const auto kds = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();
