class MyCircularQueue {
public:
    int *arr;
    int tail;
    int head;
    int size;
    int cnt;
    
    /** Initialize your data structure here. Set the size of the queue to be k. */
    MyCircularQueue(int k) {
        arr = new int[k];
        tail = 0;
        head = 0;
        size = k;
        cnt = 0;
    }
    
    /** Insert an element into the circular queue. Return true if the operation is successful. */
    bool enQueue(int value) {
        if(cnt == size){
            return false;
        }
        arr[tail] = value;
        cnt++;
        tail = (tail + 1) % size;
        return true;
    }
    
    /** Delete an element from the circular queue. Return true if the operation is successful. */
    bool deQueue() {
        if(cnt == 0){
            return false;
        }
        head = (head + 1) % size;
        cnt--;
        return true;
    }
    
    /** Get the front item from the queue. */
    int Front() {
        if(cnt == 0){
            return -1;
        }
        return arr[head];
    }
    
    /** Get the last item from the queue. */
    int Rear() {
        if(cnt == 0){
            return -1;
        }
        return arr[(tail + size -1) % size];
    }
    
    /** Checks whether the circular queue is empty or not. */
    bool isEmpty() {
        return cnt == 0;
    }
    
    /** Checks whether the circular queue is full or not. */
    bool isFull() {
        return cnt == size;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue obj = new MyCircularQueue(k);
 * bool param_1 = obj.enQueue(value);
 * bool param_2 = obj.deQueue();
 * int param_3 = obj.Front();
 * int param_4 = obj.Rear();
 * bool param_5 = obj.isEmpty();
 * bool param_6 = obj.isFull();
 */
