#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define FORS(I, S) for (int I = 0; S[I]; ++I)
#define REP(i,n)  FOR(i,0,n)
int myComp(pair<char, int> a, pair<char, int> b){
    return a.second < b.second;        
}

class Solution {
public:

    
    int leastInterval(vector<char>& tasks, int n) {
        if(n == 0){
            return tasks.size();
        }
        map <char, int> taskmap;

        int FINISH = tasks.size();
        FOR(i, 0, tasks.size()){
            taskmap[tasks[i]]++;
        }
        
        int job_count = 0;
        int time_frame = 0;
        
        int running_time[26];
        FOR(i, 0, 26){
            running_time[i] = -n -1;
        }
        
        while(job_count < FINISH){
            // find valid time frame
            vector<pair<char, int>> v;
            for(map<char, int>::iterator it=taskmap.begin(); it != taskmap.end(); it++)
                v.push_back(make_pair(it->first,it->second));   

            make_heap(v.begin(),v.end(), myComp);
            
            bool idle = true;
            while(v.size()!=0){
                
                pair<char, int> p = v.front();
                pop_heap(v.begin(), v.end(), myComp); v.pop_back();
                if(p.second == 0){
                    continue;
                }
                
                if( time_frame - running_time[p.first - 65] > n){
                    // valid choice
                    running_time[p.first - 65] = time_frame++;
                    taskmap[p.first] --;
                    job_count++;
                    idle = false;
                    
                    
                    if(taskmap[p.first] == 0){
                        running_time[p.first - 65] = INT_MAX;
                    }
                    
                    break;
                }
            }
            if(idle == true){
                // jump to next possible time
                // find min time frame and add n
                int min =  INT_MAX;
                FOR(i, 0, 26){
                    if(running_time[i] >=0 && running_time[i] < min){
                        min = running_time[i];
                    }
                }
                time_frame = min + n +1;
            }
        }
        
        
        return time_frame;
    }
};
