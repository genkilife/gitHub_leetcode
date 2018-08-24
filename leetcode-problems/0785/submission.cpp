class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        
        vector<int> color(graph.size(), 0);
        vector<int> visited(graph.size(), 0);
        deque<int> dq;
        int N=0;
        dq.push_back(0);
        while(dq.size()!=0){
            int i = dq.front();
            dq.pop_front();
            
            if(visited[i] == 0){
                // default color 1
                visited[i] = 1;
                N++;
            }
            
            if (visited[i] == 1){
                // check next 2
                for(int j=0; j<graph[i].size(); j++){
                    if(visited[graph[i][j]] == 1){
                        return false;
                    } else if (visited[graph[i][j]] == 0){
                        visited[graph[i][j]] = 2;
                        N++;
                        dq.push_back(graph[i][j]);
                    }
                }
                
            } else if (visited[i] == 2){
                // check next 1
                for(int j=0; j<graph[i].size(); j++){
                    if(visited[graph[i][j]] == 2){
                        return false;
                    } else if (visited[graph[i][j]] == 0){
                        visited[graph[i][j]] = 1;
                        N++;
                        dq.push_back(graph[i][j]);
                    }
                }
            }
            if(dq.size()==0 && N<graph.size()){
                // find next posible 
                for(int i=1; i<visited.size(); i++){
                    if(visited[i]==0){
                        dq.push_back(i);
                        break;
                    }
                }
            }
        }
        return true;
        
    }
};
