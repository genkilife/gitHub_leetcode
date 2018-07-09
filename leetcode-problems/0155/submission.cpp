class MinStack {
public:
    vector<int> queue;
    /** initialize your data structure here. */
    MinStack() {
        queue.clear();
        
    }
    
    void push(int x) {
        queue.push_back(x);
    }
    
    void pop() {
        queue.pop_back();
    }
    
    int top() {
        return queue.back();
        
    }
    
    int getMin() {
        int min ;
        if(queue.size()!=0){
            min = queue[0];
        }
        for(int i=1; i<queue.size(); i++){
            if(min > queue[i]){
                min = queue[i];
            }
        }
        return min;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(x);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */
