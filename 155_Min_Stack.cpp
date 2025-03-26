class MinStack {
public:
    stack<int> st,minSt;
    MinStack() {
        
    }
    
    void push(int val){
        if(minSt.empty() || val <= minSt.top()){
            minSt.push(val);
            st.push(val);
        }else{
            st.push(val);
        }
    }
    
    void pop() {
        if(st.top() == minSt.top()){
            minSt.pop();
            st.pop();
        }
        else if(!st.empty()){
            st.pop();
        }
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return minSt.top();
    }
};
static const auto kds = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();
/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
