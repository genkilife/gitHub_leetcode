class MyQueue {
public:
    vector<int> queue;
    /** Initialize your data structure here. */
    MyQueue() {
        queue.clear();
    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        queue.push_back(x);        
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        int x = queue[0];
        queue.erase(queue.begin());
        return x;
    }
    
    /** Get the front element. */
    int peek() {
        return queue[0];
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return queue.size()==0;
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue obj = new MyQueue();
 * obj.push(x);
 * int param_2 = obj.pop();
 * int param_3 = obj.peek();
 * bool param_4 = obj.empty();
 */
