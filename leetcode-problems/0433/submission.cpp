class Solution {
public:
    int minMutation(string start, string end, vector<string>& bank) {
        int flag = false;
        int stop;
        for(stop=0; stop<bank.size(); stop++){
            if(bank[stop]==end){
                flag=true;
                break;
            }
        }
        if(flag==false){
            return -1;
        }
        
        
        bank.insert(bank.begin(), start);
        vector<int> init(bank.size(), INT_MAX/2);
        vector<vector<int>> dist(bank.size(), init);
        for(int i=0; i<dist.size(); i++){
            for(int j=i; j<dist[0].size();j++){
                int cnt=0;
                for(int k=0; k<bank[i].length(); k++){
                    if(bank[i][k] != bank[j][k]){
                        cnt++;
                    }
                }
                if(cnt <= 1){
                    dist[i][j] = cnt;
                    dist[j][i] = cnt;
                }
            }
        }
        

        
        deque<int> dq;
        dq.push_back(0);
        
        while(dq.size()!=0){
            // relax
            int src = dq.front();
            dq.pop_front();
            for(int i=0; i<dist.size(); i++){
                // src goes to i
                if(src==i){
                    continue;
                }
                int min = INT_MAX;
                for(int j=0; j<dist[0].size(); j++){
                    if(dist[src][j] + dist[j][i] < dist[src][i]){
                        min = dist[src][j] + dist[j][i];
                    }
                }
                if(min != INT_MAX){
                    dist[src][i] = min;
                    dq.push_back(i);
                }
            }
        }
        
        if(dist[0][stop+1] != INT_MAX/2){
            return dist[0][stop+1];
        } else{
            return -1;
        }
    }
};
