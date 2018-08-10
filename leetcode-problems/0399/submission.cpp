using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
typedef long double LD;
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<LL> VL;
typedef vector<VL> VVL;
typedef vector<PII> VPII;
typedef pair<LL,LL> PLL;
typedef vector<PLL> VPLL;
typedef vector<string> VS;

#define SL(a) int((a).length())
#define SZ(a) int((a).size())
#define ALL(a)  begin((a)),end((a))
#define RALL(a) (a).rbegin(), (a).rend()
#define PB push_back
#define EB emplace_back
#define MP make_pair
#define MT make_tuple

#define SORT(c) sort(ALL((c)))
#define RSORT(c) sort(RALL((c)))
#define UNIQ(c) (c).erase(unique(ALL((c))), end((c)))
#define SORT_UNIQUE(c) (sort(c.begin(),c.end()), c.resize(distance(c.begin(),unique(c.begin(),c.end()))))
#define GET_POS(c,x) (lower_bound(c.begin(),c.end(),x)-c.begin())

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define FORS(I, S) for (int I = 0; S[I]; ++I)
#define REP(i,n)  FOR(i,0,n)

#define FF first
#define SS second

#define DUMP(x) cout<<#x<<":"<<(x)<<endl

const double EPS = 1e-10;
const double PI  = acos(-1.0);
const LL MOD = 1e9+7;

class Solution {
public:
    bool DFS(int src_i, int dst_i, vector< vector<double> >& graph, vector<int>& stack, vector<int>& mask){
        //cout<<" visit: "<<src_i<< " dst: "<<dst_i<<endl;
        stack.PB(src_i);
        mask[src_i] = 1;
        if(src_i == dst_i){
            return true;
        }
        FOR(i, 0, SZ(graph[src_i])){
            
            if(graph[src_i][i] > 0.0 && mask[i] == 0){
                // next permute
                if(DFS(i, dst_i, graph, stack, mask)){
                    return true;
                }
            }
        }
        stack.pop_back();
        mask[src_i] = 0;
        //cout<<" outvisit: "<<src_i<< " dst: "<<dst_i<<endl;
        return false;
    }
    
    vector<double> calcEquation(vector<pair<string, string>> equations, vector<double>& values, vector<pair<string, string>> queries) 
    {
        set<string> node_set;
        FOR(i, 0, SZ(equations)){
            node_set.insert(equations[i].first);
            node_set.insert(equations[i].second);
        }
        
        set<string>::iterator iter_set;
        map<string, int> index;
        int cnt=0;
        for(iter_set = node_set.begin(); iter_set != node_set.end(); iter_set++){
            index[*iter_set] = cnt++;
        }
        
        vector<double> init_v(SZ(node_set), -1.0);
        vector< vector<double> > graph(SZ(node_set), init_v);
        
        FOR(i, 0, SZ(graph)){
            graph[i][i] = 1.0;
        }
            
        
        FOR(i, 0, SZ(equations)){
            string src = equations[i].first;
            string dst = equations[i].second;
            
            int src_i = index[src];
            int dst_i = index[dst];
            
            graph[src_i][dst_i] = values[i];
            graph[dst_i][src_i] = 1.0 / values[i];
            
        }
        /*
        FOR(i, 0, SZ(graph)){
            FOR(j, 0, SZ(graph[0])){
                cout<<graph[i][j]<<" ";
            }
            cout<<endl;
        }*/
        
        vector<double> ans;
        FOR(i, 0, SZ(queries) ) {
            string src = queries[i].first;
            string dst = queries[i].second;
            
            if(index.find(src) == index.end()){
                ans.PB(-1.0);
                continue;
            }
            if(index.find(dst) == index.end()){
                ans.PB(-1.0);
                continue;
            }
            
            int src_i = index[src];
            int dst_i = index[dst];
            //cout<<"souce: "<<src_i<<" dst: "<<dst_i<<endl;
            
            vector<int> mask(SZ(graph), 0);
            vector<int> stack;
            stack.PB(src_i);
            // find path from src to dst
            if( DFS(src_i, dst_i, graph, stack, mask) == false){
                ans.PB(-1.0);
            } else {
                // stack
                double num = 1.0;
                /*
                FOR(j, 0, SZ(stack)){
                    cout<<stack[j]<<" ";
                }
                cout<<endl;
                */
                
                FOR(j, 0, SZ(stack)-1) {
                    num *= graph[stack[j]][stack[j+1]];
                    //cout<<"num: "<<num<<endl;
                }
                ans.PB(num);
            }
        }
        
        return ans;
    }
};
