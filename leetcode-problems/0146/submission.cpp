class LRUCache {
public:
    int N;
    map<int, int> LRUmap;
    deque<int> dq;
    LRUCache(int capacity) {
        N = capacity;
        LRUmap.clear();
    }
    
    int get(int key) {
        if(LRUmap.find(key) != LRUmap.end()){
            for(int i=0; i<dq.size(); i++){
                if(dq[i] == key){
                    dq.erase(dq.begin()+i);
                    dq.push_back(key);
                    break;
                }
            }
            return LRUmap[key];
        } else{
            return -1;
        }
    }
    
    void put(int key, int value) {
        if(LRUmap.find(key) != LRUmap.end()){
            LRUmap[key] = value;
            for(int i=0; i<dq.size(); i++){
                if(dq[i] == key){
                    dq.erase(dq.begin()+i);
                    dq.push_back(key);
                    break;
                }
            }
        }
        else if(dq.size() == N){
            // need replace
            int deleted_key = dq.front();
            LRUmap.erase(deleted_key);
            dq.pop_front();
            
            LRUmap[key] = value;
            dq.push_back(key);
        } else{
            LRUmap[key] = value;
            dq.push_back(key);
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache obj = new LRUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */
