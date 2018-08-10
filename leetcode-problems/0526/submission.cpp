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
    void DFS(vector<int> arr, int N, int& cnt){
        /*
        cout<<"visit:"<<endl;
        FOR(i, 1, SZ(arr)){
            cout<<arr[i];
        }
        cout<<endl;
        */
        if(N == 0){
            cnt++;
            return;
        }
        
        FOR(i, 1, SZ(arr)){
            if(arr[i] > 0){
                continue;
            }
            if(N%i == 0 || i%N == 0){
                vector<int> in = arr;
                in[i] = N;
                DFS(in, N-1, cnt);
            }
        }
        return;
        
    }
    
    int countArrangement(int N) {
        


        vector<int> arr(N+1, 0);
        

                
        int cnt = 0;
        FOR(i, 1, SZ(arr)){
            if(N%i == 0){
                vector<int> in = arr;
                in[i] = N;
                DFS(in, N-1, cnt);
            }
        }

        return cnt;
    }
};
