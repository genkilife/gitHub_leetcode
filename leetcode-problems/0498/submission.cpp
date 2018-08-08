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
    vector<int> findDiagonalOrder(vector<vector<int>>& matrix) {
        if(SZ(matrix)==0 || SZ(matrix[0]) ==0){
            vector<int> tmp;
            return tmp;
        }
        
        VI ans;
        
        int index = 0;
        
        int M = SZ(matrix);
        int N = SZ(matrix[0]);
        
        bool direct = false;
        FOR(i, 0, M+N-1){
            //cout<<"loop: "<<i<<endl;
            if(direct == false){
                int x = i;
                int y = 0;
                if(x >=M ){
                    x -= (i - M + 1);
                    y += (i - M + 1);
                }
                while(x>=0 && y < N){
                    //cout<<"x: "<<x<<" y: "<<y<<" matrix: "<<matrix[x][y]<<endl;
                    ans.PB(matrix[x][y]);
                    x--;
                    y++;
                }
            } else{
                int x = 0;
                int y = i;
                
                if(y >= N){
                    y -= (i-N+1);
                    x += (i-N+1);
                }
                while(x<M && y >=0){
                    //cout<<"x: "<<x<<" y: "<<y<<" matrix: "<<matrix[x][y]<<endl;
                    ans.PB(matrix[x][y]);
                    x++;
                    y--;
                }
            }
            direct = !direct;
            
        }
        return ans;
    }
};
